#include<bits/stdc++.h>
#include "game_state.h"
using namespace std;

void a_star(int **initial,int N,int blankxc,int blankyc)
{
    int xc[4]={0,0,1,-1}; // x axis move array 선언
    int yc[4]={1,-1,0,0}; // y axis move array 선언

    priority_queue<node*,vector<node*>,compare> pq; // 우선순위 큐 pq 선언
    map <vector<int>,int>m; // m이라는 map 클래스 생성, key:vector, value: int

    node* root=newnode(initial,NULL,0,blankxc,blankyc,blankxc,blankyc,N, 100); // 루트 노트 생성
    pq.push(root); // PQ에 root push

    while(!pq.empty())
    { 
        node* curr=pq.top();  // PQ의 가장 높은 우선순위를 가진 노드 curr에 저장
        pq.pop(); // 해당 노드 삭제

        vector<int>temp; // temp vector 생성
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                temp.push_back(curr->mat[i][j]); // temp 벡터에 curr노드의
        }
        m[temp]=1; // key: temp, value = 1

        if(curr->heuri==0) // 정답이랑 같으면: 바꿀게 없으면 끝
        {   
            print_direction(curr); // 방향 출력
            // cout << endl;
            // print(curr,N); // 노드 출력
            return;
        }

        int bx=curr->blankx; // 새로운 blank xais -> bx
        int by=curr->blanky; // 새로운 blank yais -> by
        for(int i=0;i<4;i++)
        {   
            // 모든 방향으로 자식 노드를 만든다.
            if(is_valid(bx+xc[i],by+yc[i],N)) // 좌표값을 벗어나지 않았으면
            {   // 자식 노드 생성 -> 자식노드 값: mat, 부모 노드: curr, 깊이 +1, 현재 blank 좌표, 바꿀 blank 좌표
                node* child=newnode(curr->mat,curr,curr->level+1,bx,by,bx+xc[i],by+yc[i],N, i);
                vector<int> v; // v 벡터 생성
                for(int i=0;i<N;i++)
                {
                    for(int j=0;j<N;j++)
                    v.push_back((child->mat)[i][j]);
                }
                if(m.find(v)==m.end()){
                pq.push(child);

                } // 계산한 자식 노드가 기존에 계산되지 않을 경우 PQ에 push
                else // 기존에 있는 값이면 제거
                    delete(child);
            }
        }
    }
}

// 처음에는 루트 노드만 넣고 node를 생성함.
// 이후 4방향으로 자식 노드들을 생성해서 맨해튼 값, level 값들을 통해서 cost value를 계산함.
// cost-value 값을 바탕으로 우선순위 큐에 오름차순으로 저장되므로, 가장 작은 노드가 선택될 다음 좌표!

// 발전 가능성

// 1. 이전 위치로 돌아가는 자식 노드까지 계산한다고 판단됨. 이를 지우면 계산 방향 -1
// 2. 현재는 정방 행렬에서만 돌아감 -> 껍질을 벗기는 계산을 이뤄내야함.
// 3. 방향값을 출력하는 것도 확인해봐야함.

// 3는 node에대가 direction index까지 같이 넣어줘야함.
// 그리고 문제는 노드가 계속 밑으로 달려서 역순으로 direction index의 접근이 가능함.