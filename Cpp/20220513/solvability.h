int get_invcnt(int **initial,int N)
{
    int res=0;

    int arr[N*N];
    int curr=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        arr[curr++]=initial[i][j];
    }

    for (int i=0;i<N*N-1;i++)
    {
        for(int j=i+1;j<N*N;j++)
        {
            if (arr[j] && arr[i] && arr[i] > arr[j])
                res++;
        }
    }
    return res;
}

int get_position(int **initial,int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(initial[i][j]==0)
            return N-i;
        }
    }

    return -1;
}

bool is_solvable(int** initial,int N)
{
    int inv_count=get_invcnt(initial, N);
    if(N%2==1)
    {
        if(inv_count%2==0)
            return true;
        else
            return false;
    }
    else
    {
        int pos=get_position(initial,N);
        if((inv_count+pos)%2==1)
            return true;
        else
            return false;
    }
}