#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char a[n];
    scanf("%s", a);
    if (k > n / 2)
    {
        while (k < n)
        {
            printf("RIGHT\n");
            k++;
        }
    }
    else
    {
        while (k > 1)
        {
            printf("LEFT\n");
            k--;
        }
    }
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("PRINT %c\n", a[i]);
            if ((i + 1) < n)
            {
                printf("RIGHT\n");
            }
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            printf("PRINT %c\n", a[i]);
            if ((i - 1) >= 0)
            {
                printf("LEFT\n");
            }
        }
    }
    return 0;
}

