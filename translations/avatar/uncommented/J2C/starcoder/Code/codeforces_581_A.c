#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, count = 0;
    scanf("%d %d", &a, &b);
    while(a > 0 && b > 0)
    {
        count++;
        a--;
        b--;
    }
    int ans = a/2 + b/2;
    printf("%d %d\n", count, ans);
    return 0;
}
