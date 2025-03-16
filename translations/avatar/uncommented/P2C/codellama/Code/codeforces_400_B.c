
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char s[n][m];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
    }
    int c[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = strchr(s[i], 'S') - strchr(s[i], 'G');
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (c[i] < 0)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        printf("-1");
    }
    else
    {
        printf("%d", n);
    }
    return 0;
}

