
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    char s[100000];
    while (n > 0)
    {
        int x = n % 2;
        n /= 2;
        s[ans] = x + '0';
        ans++;
    }
    for (int i = 0; i < ans; i++)
    {
        if (s[i] == '1')
        {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}

