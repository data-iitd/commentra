
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, testCase, num, i, ans;
    char s[100000];
    scanf("%d", &n);
    for (testCase = 1; testCase <= n; testCase++)
    {
        scanf("%d", &num);
        scanf("%s", s);
        char sb[100000];
        for (i = 1; i < num; i++)
        {
            sb[i - 1] = abs(s[i] - s[i - 1]);
        }
        sb[i - 1] = '\0';
        if (num == 2)
        {
            printf("%c\n", sb[0]);
            continue;
        }
        if (strstr(sb, "1")!= NULL)
        {
            ans = 0;
            for (i = 0; i < num; i++)
            {
                if (s[i] == '1')
                {
                    ans ^= 1;
                }
            }
            printf("%d\n", ans);
        }
        else
        {
            ans = 0;
            for (i = 0; i < num; i++)
            {
                if (s[i] == '2')
                {
                    ans ^= 1;
                }
            }
            printf("%d\n", ans * 2);
        }
    }
    return 0;
}

