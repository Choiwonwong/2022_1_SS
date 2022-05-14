#include<bits/stdc++.h>
using namespace std;

char di[] = "RLDU";
// node란 구조체 정의
struct node{
    int **mat; // mat?
    node* parent; // 부모 노드
    int heuri; // 휴리스틱 값
    int level; // 아마 깊이일듯?
    int blankx; // blank의 x 좌표
    int blanky; // black의 y 좌표
    int direction; // 이동 방향
};

// 교체해야하는 위치의 휴리스틱 값을 계산하는 함수
// 이거 정답 보드와 다른 좌표의 개수를 반환하는듯?
// 위치에 올바른 값이 얼마나 들어잇는지 계산해주는 함수
int calc_heuristic_misplaced(int** curr,int N)
{
    int res=0; // 다른 원소 값
    int val=1; // 정답 배열의 값
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(curr[i][j]==0)
            {
                val++;
                continue;
            }
            if(curr[i][j]!=0 && curr[i][j]!=val)
                res++;
            val++;
        }
    }
    return res;
}

// 맨해튼 값을 계산하는 함수? 휴리스틱 값을 계산하는 함수?
// 잘 모르겠음 -> 이것을 계산해야 정답 배열을 바꿀 수 있음.
int calc_heuristic_manhattan(int **curr,int N)
{
    map<int,pair<int,int> > sol_map;
    int val=1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==N-1 && j==N-1)
                sol_map[0]=make_pair(i,j);
            else
                sol_map[val]=make_pair(i,j);

            val++;
        }
    } // sol_map은 정답 board
    int res=0;
    for(int i=0;i<N;i++) // 정답 board의 값을 바탕으로 맨해튼 거리의 합 계산
    {
        for(int j=0;j<N;j++)
        {
            pair<int,int> p=sol_map[curr[i][j]]; 
            // curr board의 원소 값에 따라 sol_map의 저장되어있는 
            // 좌표값을 p에 저장해서 정답 board의 좌표와의 맨해튼 거리의 합을 더한다.
            res+=abs(i-p.first)+abs(j-p.second);
        }
    }

    return res;
}

// newnode란 노드 객체 생성
node* newnode(int **initial,node* parent,int level,int bx,int by,int newx,int newy,int N, int direct)
{
    node* temp=new node; // temp라는 새로운 노드 생성?
    int **curr=new int*[N]; // initial을 따르는curr라는 board 생성
    for(int i=0;i<N;i++)
    {
        curr[i]=new int[N];
        for(int j=0;j<N;j++)
            curr[i][j]=initial[i][j];
    }
    // 공백의 newx, newy값과 swap
    swap(curr[bx][by],curr[newx][newy]);
    temp->mat=curr;
    temp->parent=parent;
    temp->heuri=calc_heuristic_manhattan(curr,N); // 바꾼 board의 휴리스틱 값 계산
    temp->level=level;
    temp->blankx=newx;
    temp->blanky=newy;
    temp->direction = direct;

    // 즉 initial board를 newx, newy에 따라서 변경해줌.

    return temp;
}
// x, y가 유효한지 확인해줌. 즉, 좌표가 벗어났는지 확인해주는 함수
bool is_valid(int x,int y,int N)
{
    return (x>=0 && x<N && y>=0 && y<N);
}
// 노드 의의 heuri값 + level 값이 n1이 크면 true, n2가 크면 falsa 반환
struct compare
{
    bool operator()(const node* n1,const node* n2)const
    {
        return (n1->heuri+n1->level)>(n2->heuri+n2->level);
    }
};
// 볼필요 X
void print(node* curr,int N)
{
    if(curr->parent==NULL)
        return;

    print(curr->parent,N);

   for(int i=0;i<N;i++)
    {
        cout<<'[';
        for(int j=0;j<N;j++)
        {
                cout<<(curr->mat)[i][j]<<" ";
        }
        cout<<"\b]"<<endl;
    }
    cout<<endl;
    return;
}

void print_direction(node* curr)
{   
    if(curr->parent==NULL)
        return;

    print_direction(curr->parent);

    // cout<<curr->direction;
    cout<<di[curr->direction];
    return;
}