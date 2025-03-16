#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        if(i == N - 1)
            count++;
        else if(A[i] == A[i + 1])
            ;
        else if(A[i] < A[i + 1])
        {
            while(A[i] <= A[i + 1])
            {
                i++;
                if(i == N - 1)
                    break;
            }
            count++;
        }
        else
        {
            while(A[i] >= A[i + 1])
            {
                i++;
                if(i == N - 1)
                    break;
            }
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
