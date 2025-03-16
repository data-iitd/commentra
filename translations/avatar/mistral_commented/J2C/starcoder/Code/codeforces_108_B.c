
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, flag = 0;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n - 1; i++)
    {
        if(a[i] * 2 == a[i + 1])
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}

