#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, c = 0, f = 1;
    scanf("%d", &n);
    int l[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (l[i] > c)
        {
            c++;
        }
    }
    printf("%d", c + 1);
    return 0;
}

