#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, a, y;
    scanf("%d %d %d", &x, &a, &y);
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        if (x + y + a == 17) {
            printf("YES");
        } else {
            printf("NO");
        }
    } else {
        printf("NO");
    }
    return 0;
}
