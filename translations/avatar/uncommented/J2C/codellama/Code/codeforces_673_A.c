#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n, value, result, pos, flag;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        a[i] = value;
    }
    if (a[0] > 15)
        result = 15;
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] > 15)
            {
                pos = i - 1;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            result = a[pos] + 15;
        else
            result = a[n - 1] + 15;
    }
    if (result > 90)
        result = 90;
    printf("%d", result);
    return 0;
}
