
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, l, r, o, e;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < k; i++)
    {
        scanf("%d %d", &l, &r);
        o = 0;
        e = 0;
        for (i = l - 1; i < r; i++)
            if (arr[i] == 1)
                o++;
            else
                e++;
        if ((r - l + 1) % 2 == 1)
            printf("0\n");
        else
        {
            if ((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e)
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}

