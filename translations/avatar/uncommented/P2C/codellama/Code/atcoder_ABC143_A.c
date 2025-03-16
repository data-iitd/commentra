
#include <stdio.h>
int main()
{
    int A, B, ans;
    scanf("%d %d", &A, &B);
    ans = A - 2 * B;
    if (ans < 0)
        ans = 0;
    printf("%d", ans);
    return 0;
}
