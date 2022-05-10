#include<bits/stdc++.h>
#include "game_state.h"
using namespace std;

void a_star(int **initial,int N,int blankxc,int blankyc)
{
    int xc[4]={0,0,1,-1};
    int yc[4]={1,-1,0,0};

    priority_queue<node*,vector<node*>,compare> pq;
    map <vector<int>,int>m;

    node* root=newnode(initial,NULL,0,blankxc,blankyc,blankxc,blankyc,N);
    pq.push(root);

    while(!pq.empty())
    {
        node* curr=pq.top();
        pq.pop();

        vector<int>temp;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                temp.push_back(curr->mat[i][j]);
        }
        m[temp]=1;
        if(curr->heuri==0)
        {
            print(curr,N);
            return;
        }

        int bx=curr->blankx;
        int by=curr->blanky;
        for(int i=0;i<4;i++)
        {
            if(is_valid(bx+xc[i],by+yc[i],N))
            {
                node* child=newnode(curr->mat,curr,curr->level+1,bx,by,bx+xc[i],by+yc[i],N);
                vector<int> v;
                for(int i=0;i<N;i++)
                {
                    for(int j=0;j<N;j++)
                    v.push_back((child->mat)[i][j]);
                }
                if(m.find(v)==m.end())
                pq.push(child);
                else
                    delete(child);
            }
        }
    }
}

void bfs(int **initial,int N,int blankxc,int blankyc)
{
    int xc[4]={0,0,1,-1};
    int yc[4]={1,-1,0,0};

    queue<node*> q;
    map <vector<int>,int>m;

    node* root=newnode(initial,NULL,0,blankxc,blankyc,blankxc,blankyc,N);
    q.push(root);

    vector<int> final_mat;
    for(int i=1;i<N*N;i++)
        final_mat.push_back(i);
    final_mat.push_back(0);

    while(!q.empty())
    {
        node* curr=q.front();
        q.pop();

        vector<int>temp;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                temp.push_back(curr->mat[i][j]);
        }
        m[temp]=1;

        if(temp==final_mat)
        {
            print(curr,N);
            return;
        }

        int bx=curr->blankx;
        int by=curr->blanky;
        for(int i=0;i<4;i++)
        {
            if(is_valid(bx+xc[i],by+yc[i],N))
            {
                node* child=newnode(curr->mat,curr,0,bx,by,bx+xc[i],by+yc[i],N);
                vector<int> v;
                for(int i=0;i<N;i++)
                {
                    for(int j=0;j<N;j++)
                    v.push_back((child->mat)[i][j]);
                }
                if(m.find(v)==m.end())
                q.push(child);
                else
                    delete(child);
            }
        }
    }
}


