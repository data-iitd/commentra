
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, K, i, j, l, r, c, tot, x, ll, rr;
    int *A;

    scanf("%d %d", &N, &K);
    A = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    qsort(A, N, sizeof(int), compare);

    ll = -1000000000 - 1;
    rr = 1000000000 + 1;

    while (ll + 1 < rr)
    {
        x = (ll + rr) / 2;
        tot = 0;

        for (i = 0; i < N; i++)
        {
            if (A[i] < 0)
            {
                l = -1;
                r = N;
                while (l + 1 < r)
                {
                    c = (l + r) / 2;
                    if (A[i] * A[c] < x)
                        r = c;
                    else
                        l = c;
                }
                tot += N - r;
            }
            else
            {
                l = -1;
                r = N;
                while (l + 1 < r)
                {
                    c = (l + r) / 2;
                    if (A[i] * A[c] < x)
                        l = c;
                    else
                        r = c;
                }
                tot += r;
            }

            if (A[i] * A[i] < x)
                tot--;
        }

        tot /= 2;

        if (tot < K)
            ll = x;
        else
            rr = x;
    }

    printf("%d\n", ll);

    free(A);
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

