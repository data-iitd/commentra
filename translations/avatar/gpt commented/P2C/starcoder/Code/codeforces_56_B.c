#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, mn, mx;
    int A[100000];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    mn = N + 1;
    mx = -1;
    for (i = 0; i < N; i++)
    {
        if (i + 1!= A[i])
        {
            mn = (mn < i)? mn : i;
            mx = (mx > i)? mx : i;
        }
    }

    if (mx == -1)
        printf("0 0\n");
    else
    {
        int temp[100000];
        int j = 0;
        for (i = 0; i < N; i++)
        {
            if (i < mn || i > mx)
                temp[j++] = A[i];
        }
        for (i = mn; i <= mx; i++)
            temp[j++] = A[i];
        for (i = 0; i < N; i++)
            A[i] = temp[i];

        if (sorted(A, N))
            printf("%d %d\n", mn + 1, mx + 1);
        else
            printf("0 0\n");
    }

    return 0;
}

