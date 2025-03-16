#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *ans = (int *)malloc(n * sizeof(int));
    int mx = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(0, mx - arr[i] + 1);
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("