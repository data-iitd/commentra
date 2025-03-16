
#include <stdio.h>

int main() {
    int n, count;
    scanf("%d %d", &n, &count);
    int a = (n + 1) / 2;
    int b = n / 2;
    int max = a * a + b * b;
    if (count > max) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0 && count > 0) {
                printf("L");
                count--;
            } else {
                printf("S");
            }
        }
        printf("\n");
    }
    return 0;
}
// END-OF-CODE