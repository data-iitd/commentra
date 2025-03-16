#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    printf("%d ", n);
    m = n;
    for (int i = n - 1; i > 0; i--) {
        if (m % i == 0) {
            printf("%d ", i);
            m = i;
        }
    }
    printf("\n");
    return 0;
}
