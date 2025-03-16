#include <stdio.h>

int main()
{
    int n, i, h1 = 0, h2 = 0, x = 0;
    scanf("%d", &n);
    int number[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &number[i]);
        if (number[i] != 4 && number[i] != 7)
        {
            printf("NO");
            x = 1;
            break;
        }
        if (i < n / 2)
        {
            h1 += number[i];
        }
        else
        {
            h2 += number[i];
        }
    }
    if (!x)
    {
        if (h1 == h2)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }
    return 0;
}
