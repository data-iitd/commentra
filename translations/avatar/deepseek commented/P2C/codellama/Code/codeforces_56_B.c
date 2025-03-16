
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int mn = N + 1, mx = -1;
    for (int i = 0; i < N; i++)
    {
        if (i + 1 != A[i])
        {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    if (mx == -1)
    {
        printf("0 0\n");
    }
    else
    {
        for (int i = mn; i <= mx; i++)
        {
            A[i] = A[i] + 1;
        }
        int flag = 1;
        for (int i = 0; i < N; i++)
        {
            if (A[i] != i + 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d %d\n", mn + 1, mx + 1);
        }
        else
        {
            printf("0 0\n");
        }
    }

    return 0;
}

