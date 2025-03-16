#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int K;
    scanf("%d", &K);
    if (K % 2 == 0 || K % 5 == 0)
        printf("-1\n");
    else if (K % 7 == 0)
        K /= 7;
    K *= 9;
    int ans = 1;
    int remainder = 10 % K;
    while (remainder!= 1)
    {
        ans++;
        remainder = remainder * 10 % K;
    }
    printf("%d\n", ans);
    return 0;
}
