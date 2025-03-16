#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, odd = 0, even = 0;
    scanf("%d", &n);
    int *list = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
        if (list[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    if (odd == 1)
    {
        printf("%d\n", list[0]);
    }
    else
    {
        printf("%d\n", list[even]);
    }
    return 0;
}
