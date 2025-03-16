#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, ans, m;
    char s[1000000];
    scanf("%d", &n);
    scanf("%s", s);
    m = n - 1;
    ans = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '1' && (m & i) == i)
        {
            ans ^= 1;
        }
    }
    if (n == 2)
    {
        printf("%c", s[0]);
    }
    else
    {
        if (ans == 1)
        {
            printf("%d", cal(s, '1'));
        }
        else
        {
            printf("%d", cal(s, '2') * 2);
        }
    }
    return 0;
}

int cal(char s[], char c)
{
    int n = strlen(s);
    int m = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c && (m & i) == i)
        {
            ans ^= 1;
        }
    }
    return ans;
}

