
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    int ans = 0;
    for (int i = n - 2; i >= n - 2 * n - 1; i -= 2)
    {
        ans += A[i];
    }
    printf("%d", ans);
    return 0;
}

