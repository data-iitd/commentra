#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t, k, n, m;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &k, &n, &m);
        if(k * m >= n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
