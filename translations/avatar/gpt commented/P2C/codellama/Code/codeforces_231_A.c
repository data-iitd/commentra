#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, c = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int l1[100], j, sum = 0;
        char str[100];
        scanf("%s", str);
        for (j = 0; j < 100; j++)
        {
            l1[j] = str[j] - '0';
        }
        for (j = 0; j < 100; j++)
        {
            sum += l1[j];
        }
        if (sum > 1)
        {
            c++;
        }
    }
    printf("%d", c);
    return 0;
}
