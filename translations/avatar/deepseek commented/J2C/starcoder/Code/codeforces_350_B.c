#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, x, y, z, ans, s, flag;
    char ss[1000000];
    scanf("%d", &n);
    int a[n+1], b[n+1], num[n+1], st[n+1];
    for(i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(i=1; i<=n; i++)
        scanf("%d", &b[i]);
    for(i=1; i<=n; i++)
        num[b[i]]++;
    for(i=1; i<=n; i++)
        st[i] = 0;
    ans = 0;
    for(i=1; i<=n; i++)
    {
        if(a[i] == 1)
        {
            st[i] = 1;
            x = b[i];
            s = 1;
            while(!st[x] && num[x] == 1 && x!= 0 && a[x]!= 1)
            {
                st[x] = 1;
                x = b[x];
                s++;
            }
            if(s > ans)
            {
                ans = s;
                strcpy(ss, "");
                for(j=0; j<s; j++)
                {
                    y = x;
                    x = b[y];
                    z = y;
                    while(z!= 0)
                    {
                        strcat(ss, " ");
                        strcat(ss, &z);
                        z = b[z];
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    printf("%s\n", ss);
    return 0;
}

