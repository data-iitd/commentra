#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%d\n", n > 2? n - 2 : 0);
    }
    return 0;
}
