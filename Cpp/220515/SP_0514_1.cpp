#include <bits/stdc++.h>
#include "solvability.h"
#include "solver.h"
using namespace std;

int N = 3;

void printBorad(int board[][3], int size){
    for(int i = 0; i <size; i++){
        printf("[");
        for(int j = 0; j <size; j++){
            printf("%d ",board[i][j]);
        }
        cout << "\b]" << endl;
    }
}

int main()
{
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

    printBorad(input_matrix, N);

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