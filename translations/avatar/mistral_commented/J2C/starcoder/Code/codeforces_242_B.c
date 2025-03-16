
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n, i, left = 1000000000, right = 0;
    scanf("%d", &n);
    int a[n], b[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        left = (left < a[i])? left : a[i];
        scanf("%d", &b[i]);
        right = (right > b[i])? right : b[i];
    }
    for(i = 0; i < n; i++)
    {
        if(left == a[i] && right == b[i])
        {
            printf("%d", i + 1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}

