
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int N;
    scanf("%d", &N);
    int *P = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &P[i]);
    }
    int *map = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i)
    {
        map[i] = i;
    }
    int *nglist = (int *)malloc(N * sizeof(int));
    int nglist_size = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        if (map[i] > map[i + 1])
        {
            nglist[nglist_size++] = i;
        }
    }
    if (nglist_size == 0)
    {
        printf("0\n");
        return 0;
    }
    int ans = min(N - nglist[0] - 1, nglist[nglist_size - 1] + 1);
    for (int i = 0; i < nglist_size - 1; ++i)
    {
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans);
    }
    printf("%d\n", ans);
    return 0;
}

