#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 1000000005
int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    int left = INF, right = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        left = min(left, a[i]);
        right = max(right, b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (left == a[i] && right == b[i])
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
