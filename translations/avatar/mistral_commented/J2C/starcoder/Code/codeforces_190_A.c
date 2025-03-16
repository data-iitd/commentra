#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if (n == 0) {
        if (m!= 0) {
            printf("Impossible\n");
        } else {
            printf("0 %d\n", 0);
        }
        return 0;
    }
    if (m <= n) {
        if (m == 0) {
            m = 1;
        }
        printf("%d %d\n", n, m + n - 1);
    } else {
        printf("%d %d\n", m, m + n - 1);
    }
    return 0;
}
