#include <stdio.h>

int main()
{
    int n, i, c = 2;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int number;
        scanf("%d", &number);
        if (number == 1)
        {
            printf("%d\n", c);
        }
        else if (number % 2 == 0)
        {
            c = 3 - c;
            printf("%d\n", c);
        }
        else
        {
            printf("%d\n", c);
        }
    }
    return 0;
}
