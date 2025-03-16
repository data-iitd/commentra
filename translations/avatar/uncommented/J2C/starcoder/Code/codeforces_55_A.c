#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i = 1, k = 0, p = 1, flag = 1;
    int a[1000];
    scanf("%d", &n);
    while (k <= n)
    {
        i += k;
        if (i >= n)
        {
            while (! (i < n))
                i = i - n;
        }
        a[i]++;
        k++;
    }
    for (i = 0; i < n; i++)
        if (a[i] == 0)
        {
            flag = 0;
            break;
        }
    if (flag)
        printf("YES");
    else
        printf("NO");
    return 0;
}
