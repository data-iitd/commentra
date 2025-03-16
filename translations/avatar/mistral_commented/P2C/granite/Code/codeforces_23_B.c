
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (a < 2) {
            printf("0\n");
            continue;
        }

        if (a >= 2) {
            printf("%d\n", a - 2);
        }
    }

    return 0;
}
