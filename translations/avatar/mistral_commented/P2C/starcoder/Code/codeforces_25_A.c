#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum = 0;
    scanf("%d", &n);
    int list[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
        sum += list[i];
    }
    if (sum == 1)
    {
        printf("The first number with remainder 1 is: %d\n", list[0]);
    }
    else
    {
        printf("The first number with remainder 0 is: %d\n", list[0]);
    }
    return 0;
}
