#include <stdio.h>

int main() {
    int n, x;

    while (1) {
        scanf("%d %d", &n, &x);
        if (n == 0 && x == 0) {
            break;
        }

        int c = 0;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (i + j + k == x) {
                        c++;
                    }
                }
            }
        }
        printf("%d\n", c);
    }

    return 0;
}

// <END-OF-CODE>
