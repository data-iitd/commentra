#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char s[n];
    scanf("%s", s);
    int count[26] = {0};
    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'A']++;
    }
    int res = 0;
    for (int i = 25; i >= 0; i--)
    {
        if (count[i] >= k)
        {
            res += k * k;
            printf("%d\n", res);
            return 0;
        }
        k -= count[i];
        res += count[i] * count[i];
    }
    printf("%d\n", res);
    return 0;
}
