#include<bits/stdc++.h>
using namespace std;

struct node{
    int **mat;
    node* parent;
    int heuri;
    int level;
    int blankx;
    int blanky;
};

int calc_heuristic_misplaced(int** curr,int N)
{
    int res=0;
    int val=1;
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

int calc_heuristic_manhattan(int **curr,int N)
{
    map<int,pair<int,int>> sol_map;
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
    }
    int res=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            pair<int,int> p=sol_map[curr[i][j]];
            res+=abs(i-p.first)+abs(j-p.second);
        }
    }

    return res;
}

node* newnode(int **initial,node* parent,int level,int bx,int by,int newx,int newy,int N)
{
    node* temp=new node;
    int **curr=new int*[N];
    for(int i=0;i<N;i++)
    {
        curr[i]=new int[N];
        for(int j=0;j<N;j++)
            curr[i][j]=initial[i][j];
    }
    swap(curr[bx][by],curr[newx][newy]);
    temp->mat=curr;
    temp->parent=parent;
    temp->heuri=calc_heuristic_manhattan(curr,N);
    temp->level=level;
    temp->blankx=newx;
    temp->blanky=newy;

    return temp;
}

bool is_valid(int x,int y,int N)
{
    return (x>=0 && x<N && y>=0 && y<N);
}

struct compare
{
    bool operator()(const node* n1,const node* n2)const
    {
        return (n1->heuri+n1->level)>(n2->heuri+n2->level);
    }
};

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
            if(j!=N-1)
                cout<<(curr->mat)[i][j]<<" ";
            else
                 cout<<(curr->mat)[i][j];
        }
        cout<<']'<<endl;
    }
    cout<<endl;
    return;
}