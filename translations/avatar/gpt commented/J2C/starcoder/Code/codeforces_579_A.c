#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n > 0) {
        int x = n % 2;
        n /= 2;
        ans += x;
    }
    printf("%d\n", ans);
    return 0;
}

