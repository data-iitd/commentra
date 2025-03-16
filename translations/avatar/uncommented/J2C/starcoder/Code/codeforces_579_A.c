#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[100000];
    int i = 0;
    while(n > 0)
    {
        int x = n % 2;
        n /= 2;
        s[i] = x + '0';
        i++;
    }
    int ans = 0;
    for(int j = 0; j < i; j++)
    {
        if(s[j] == '1')
        {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
