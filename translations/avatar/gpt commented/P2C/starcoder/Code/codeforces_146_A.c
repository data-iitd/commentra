#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, h1, h2, x;
    scanf("%d", &n);
    int number[n];
    for (i = 0; i < n; i++)
        scanf("%d", &number[i]);
    h1 = h2 = x = 0;
    for (i = 0; i < n; i++)
    {
        if (number[i]!= 4 && number[i]!= 7)
        {
            printf("NO\n");
            x = 1;
            break;
        }
        if (i < n / 2)
            h1 += number[i];
        else
            h2 += number[i];
    }
    if (!x)
    {
        if (h1 == h2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
