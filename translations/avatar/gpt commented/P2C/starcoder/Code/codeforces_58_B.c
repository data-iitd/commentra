#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = n; i > 0; i--)
    {
        if (n % i == 0)
        {
            n = i;
            printf("%d ", i);
        }
    }

    printf("