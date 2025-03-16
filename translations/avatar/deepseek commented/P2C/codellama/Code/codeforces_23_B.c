
#include <stdio.h>

int main() {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a < 2) {
            printf("0\n");
        } else {
            printf("%d\n", a - 2);
        }
    }
    return 0;
}

