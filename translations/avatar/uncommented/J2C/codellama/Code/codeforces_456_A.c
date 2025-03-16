
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    int *a;
    int *b;
    int temp = 0;
    int q = 0;
    int w = 0, e = 0;
    bool f = false;

    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        if (temp < a[i])
        {
            if (q > b[i])
            {
                f = true;
            }
            q = b[i];
            temp = a[i];
        }
        if (temp > a[i])
        {
            if (q < b[i])
            {
                f = true;
            }
            q = b[i];
            temp = a[i];
        }
        if (a[i] > w)
        {
            w = a[i];
            if (b[i] < e)
            {
                f = true;
            }
            e = b[i];
        }
        if (a[i] < w)
        {
            if (b[i] > e)
            {
                f = true;
            }
        }
    }
    if (f == true)
    {
        printf("Happy Alex\n");
    }
    else
    {
        printf("Poor Alex\n");
    }
    return 0;
}

