#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 5 && b == 5) {
        printf("YES\n");
    } else if (a == 5 || b == 5) {
        printf("YES\n");
    } else if (a + b == 10) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
