#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int *L = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &L[i]);
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int a = L[i];
            int b = L[j];
            int res = find(L, j + 1, a + b);
            count = count + res;
        }
    }
    printf("%d", count);
    return 0;
}

int find(int *li, int from, int target)
{
    int low = from;
    int upp = N - 1;
    int mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2;
    if (upp - low < 0)
    {
        return 0;
    }
    else if (li[from] >= target)
    {
        return 0;
    }
    else if (li[upp] < target)
    {
        return upp - low + 1;
    }
    while (upp - low > 1)
    {
        if (li[mid] >= target)
        {
            upp = mid;
        }
        else
        {
            low = mid;
        }
        mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2;
    }
    return low - from + 1;
}

