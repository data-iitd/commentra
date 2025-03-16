#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n+1];
    int b[n+1];
    int num[n+1];
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d", &b[i]);
    for(int i=1; i<=n; i++)
        num[b[i]]++;
    int ans = 0;
    char ss[100000];
    for(int i=1; i<=n; i++)
    {
        if(a[i] == 1)
        {
            int x = b[i];
            int s = 1;
            while(num[x] == 1 && x!= 0 && a[x]!= 1)
            {
                s++;
                x = b[x];
            }
            if(s > ans)
            {
                ans = s;
                strcpy(ss, "");
                char sss[10];
                sprintf(sss, "%d", i);
                strcat(ss, sss);
                while(x!= 0 && a[x]!= 1)
                {
                    sprintf(sss, " %d", x);
                    strcat(ss, sss);
                    x = b[x];
                }
            }
        }
    }
    printf("%d\n", ans);
    printf("%s\n", ss);
    return 0;
}
