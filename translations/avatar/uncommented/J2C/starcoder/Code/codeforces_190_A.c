#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if (n == 0) {
        if (m!= 0) {
            printf("Impossible");
        } else {
            printf("0 %d", 0);
        }
        return 0;
    }
    if (m <= n) {
        if (m == 0) {
            m = 1;
        }
        printf("%d %d", n, m + n - 1);
        return 0;
    }
    printf("%d %d", m, m + n - 1);
    return 0;
}

