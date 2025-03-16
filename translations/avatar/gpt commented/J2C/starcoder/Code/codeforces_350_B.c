#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, ans, x, y, z, num;
    char ss[100000];
    scanf("%d", &n);
    int a[n + 1], b[n + 1], num[n + 1];
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (i = 1; i <= n; i++)
        num[b[i]]++;
    for (i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            x = b[i];
            ans = 1;
            ss[0] = i + '0';
            for (j = 1; j <= ans; j++)
            {
                ss[j] ='';
                ss[j + 1] = x + '0';
                ss[j + 2] ='';
                num[x]--;
                if (num[x] == 0)
                    break;
                x = b[x];
                ans++;
            }
            if (ans > z)
            {
                z = ans;
                for (k = 0; k <= z; k++)
                    printf("%c", ss[k]);
                printf("\n");
            }
        }
    }
    printf("%d\n", z);
    return 0;
}

