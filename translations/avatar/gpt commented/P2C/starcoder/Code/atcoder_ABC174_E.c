#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, j, mid, ans;
    scanf("%d %d", &n, &k);
    int *lis = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &lis[i]);
    ans = lis[n - 1];
    for (i = 1; i <= lis[n - 1]; i++)
    {
        mid = i;
        for (j = 0; j < n; j++)
        {
            if (lis[j] % mid == 0)
                k++;
            k -= (lis[j] / mid);
        }
        if (k >= 0)
            ans = mid;
        else
            break;
    }
    printf("%d", ans);
    return 0;
}

