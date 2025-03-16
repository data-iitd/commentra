#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    if (n < 1) {
        if (m < 1) {
            printf("%d %d\n", n, m);
            return 0;
        }
        printf("Impossible\n");
        return 0;
    }

    int min, max;
    if (m > n) {
        min = m;
        max = n + m - 1;
        printf("%d %d\n", min, max);
    } else {
        min = n;
        max = n + m - 1;
        if (m == 0) {
            max = n;
        }
        printf("%d %d\n", min, max);
    }

    return 0;
}

// <END-OF-CODE>
