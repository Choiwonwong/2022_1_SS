#include<bits/stdc++.h>
#include "solvability.h"
#include "solver.h"
using namespace std;

int main()
{
    cout<<"The size of grid(N): ";
    int N;
    cin>>N;
    int **initial=new int*[N];
    int blankxc,blankyc;
    cout<<"The shape of "<<N<<"*"<<N<<" grid:"<<endl;
    for(int i=0;i<N;i++)
    {
        initial[i]=new int[N];
        for(int j=0;j<N;j++)
        {
            cin>>initial[i][j];
            if(initial[i][j]==0)
            {
                blankxc=i;
                blankyc=j;
            }
        }
    }

    clock_t start,e;
    start=clock();
    if(!is_solvable(initial,N))
    {
        cout<<endl;
        cout<<"The given instance of sliding puzzle is not solvable."<<endl;
        e=clock();

        cout<<"Time taken to execute "<<(double)(e-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
        return 0;
    }

    cout<<endl;
    a_star(initial,N,blankxc,blankyc);

    e=clock();

    cout<<"Time taken to execute "<<(double)(e-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}