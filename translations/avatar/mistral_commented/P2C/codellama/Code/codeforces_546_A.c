
#include <stdio.h>

int main()
{
    int k, n, w, total = 0;
    scanf("%d %d %d", &k, &n, &w);

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

    return 0;
}

