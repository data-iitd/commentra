#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i;
    scanf("%d", &n);
    printf("%d ", n);
    m = n;
    for (i = n - 1; i > 0; i--)
    {
        if (m % i == 0)
        {
            printf("%d ", i);
            m = i;
        }
    }
    return 0;
}
