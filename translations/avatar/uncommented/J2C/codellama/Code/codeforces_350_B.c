
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n + 1];
    int b[n + 1];
    int num[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++)
        num[b[i]]++;
    char ss[1000];
    int ans = 0;
    bool st[n + 1];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            st[i] = true;
            char sb[1000];
            int x = b[i];
            char sss[1000];
            sprintf(sss, "%d", i);
            sprintf(sb, " %s", sss);
            int s = 1;
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1)
            {
                sprintf(sss, "%d", x);
                sprintf(sb, "%s %s", sb, sss);
                st[x] = true;
                x = b[x];
                s++;
            }
            if (s > ans)
            {
                ans = s;
                strcpy(ss, sb);
            }
        }
    }
    printf("%d\n", ans);
    printf("%s\n", ss);
    return 0;
}

