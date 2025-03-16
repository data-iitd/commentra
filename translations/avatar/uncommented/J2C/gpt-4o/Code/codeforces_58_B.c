#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);
    printf("%d\n", n);
    m = n;
    for (int i = n - 1; i > 0; i--) {
        if (m % i == 0) {
            printf("%d\n", i);
            m = i;
        }
    }
    return 0;
}

// <END-OF-CODE>
