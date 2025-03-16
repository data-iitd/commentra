#include <stdio.h>
int main(void)
{
    int A, B, ans;
    scanf("%d %d", &A, &B);
    ans = A - 2 * B;
    if (ans < 0)
        ans = 0;
    printf("%d\n", ans);
    return 0;
}
