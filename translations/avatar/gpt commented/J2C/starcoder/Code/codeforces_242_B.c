#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    int left = 1000000000, right = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        left = (left < a[i])? left : a[i];
        right = (right > b[i])? right : b[i];
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

