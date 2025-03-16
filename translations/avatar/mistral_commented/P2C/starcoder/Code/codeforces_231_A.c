#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, c = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int l1[n];
        scanf("%d", &l1[i]);
        if (sum(l1) > 1)
            c++;
    }
    printf("%d", c);
    return 0;
}
