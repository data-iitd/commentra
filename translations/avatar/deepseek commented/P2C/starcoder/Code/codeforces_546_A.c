
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k, n, w, total = 0;
    scanf("%d %d %d", &k, &n, &w);
    if (1 <= k && k <= 1000 && 1 <= w && w <= 1000)
    {
        for (int i = 1; i <= w; i++)
        {
            total += i * k;
        }
        if (total > n)
        {
            printf("%d", total - n);
        }
        else
        {
            printf("0");
        }
    }
    return 0;
}

