#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        ans += (long long)i * ((long long)n / (long long)i) * (((long long)n / (long long)i) + 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
