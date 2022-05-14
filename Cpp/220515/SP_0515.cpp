#include <bits/stdc++.h>
#include "solvability.h"
#include "solver.h"
using namespace std;

int main()
{
    int N = 3;
    // int N = 4;

    // int input_matrix[3][3] = { // LUURDDLLUURDRD
    //     {4, 2, 1}, 
    //     {7, 6, 3},
    //     {8, 5, 0}
    //     };

    // int input_matrix[3][3] = { // can't solve
    //     {1,  3,  0}, 
    //     {4,  2,  6}, 
    //     {5,  7,  8} 
    // };

    // int input_matrix[3][3] = {
    //     {4,  2,  6}, 
    //     {1,  8,  7}, 
    //     {3,  5,  0} 
    // };

    int input_matrix[3][3] = {
        {5,  4,  0}, 
        {6,  2,  8}, 
        {3,  7,  1} 
    };
    
    // int input_matrix[3][3] = {
    //     {7, 4, 2}, 
    //     {5, 6, 1},
    //     {3, 8, 0}
    //     };

    // int input_matrix[3][3] = {
    //     {1, 2, 3}, 
    //     {4, 5, 6},
    //     {0, 7, 8}
    //     };

    // int input_matrix[3][3] = {
    //     {4, 2, 1}, 
    //     {7, 6, 3},
    //     {8, 5, 0}
    //     };
    
    // int input_matrix[3][3] = {
    //     {7, 4, 2}, 
    //     {5, 6, 1},
    //     {3, 8, 0}
    //     };

    // int input_matrix[3][3] = {
    //     {1, 2, 3}, 
    //     {4, 5, 6},
    //     {0, 7, 8}
    //     };

    // 4*4

    // int input_matrix[4][4] = {
    //     {14, 7, 15, 3}, 
    //     {4, 13, 6, 8},
    //     {1, 9, 5, 2},
    //     {10, 12, 11, 0}
    //     };

    // int input_matrix[4][4] = {
    //     {1, 2, 3, 4}, 
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12},
    //     {0, 13, 14, 15}
    //     };

    // int input_matrix[4][4] = {
    //     {15, 10, 14, 1}, 
    //     {9, 5, 6, 7},
    //     {11, 4, 2, 13},
    //     {3, 8, 12, 0}
    //     };

    // int input_matrix[4][4] = {
    //     {7, 11, 1, 5}, 
    //     {6, 15, 2, 8},
    //     {4, 13, 3, 10},
    //     {9, 12, 14, 0}
    //     };

    // int input_matrix[4][4] = {
    //     {5, 4, 10, 3}, 
    //     {8, 11, 2, 14},
    //     {7, 15, 6, 13},
    //     {9, 1, 12, 0}
    //     };

    int **initial=new int*[N];
    int blankxc,blankyc;

    for(int i=0;i<N;i++)
    {
        initial[i]=new int[N];
        for(int j=0;j<N;j++)
        {
            initial[i][j] = input_matrix[i][j];
            if(initial[i][j]==0)
            {
                blankxc=i;
                blankyc=j;
            }
        }
    }

    printMatrix(initial, N);

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

    cout<< endl << endl << "Time taken to execute "<<(double)(e-start)*1000/CLOCKS_PER_SEC<<" msecs"<<endl << endl;
    return 0;
}