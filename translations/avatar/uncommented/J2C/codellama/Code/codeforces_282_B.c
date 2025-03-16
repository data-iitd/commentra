#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, j, flag = 0, dif = 0;
    int s1 = 0, s2 = 0;
    char ch[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        int temp1 = s1 + x;
        int temp2 = s2 + y;
        if (abs(temp1 - s2) <= 500)
        {
            s1 += x;
            ch[j++] = 'A';
            continue;
        }
        if (abs(temp2 - s1) <= 500)
        {
            s2 += y;
            ch[j++] = 'G';
            continue;
        }
        flag = 1;
        break;
    }
    if (flag == 1)
        printf("-1");
    else
    {
        char ans[1000];
        for (i = 0; i < j; i++)
            ans[i] = ch[i];
        ans[j] = '\0';
        printf("%s", ans);
    }
    return 0;
}

