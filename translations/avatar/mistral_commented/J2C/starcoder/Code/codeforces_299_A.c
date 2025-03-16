
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int min = a[0];
    for(int i = 0; i < n; i++)
        if(a[i] % min!= 0)
        {
            printf("-1\n");
            return 0;
        }
    printf("%d\n", min);
    return 0;
}

