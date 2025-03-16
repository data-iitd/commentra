#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, r = 0;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        r ^= a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (i!= 0)
            printf(" ");
        printf("%d", r ^ a[i]);
    }
    printf("\n");
    return 0;
}
