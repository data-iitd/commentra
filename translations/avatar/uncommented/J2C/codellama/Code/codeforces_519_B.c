#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, a = 0, b = 0, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        a += scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
        b += scanf("%d", &n);
    for (int i = 0; i < n - 2; i++)
        c += scanf("%d", &n);
    int x = a - b, y = b - c;
    printf("%d\n", x);
    printf("%d\n", y);
    return 0;
}
