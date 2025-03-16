#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int x = 0;
    int max_black = (n * n + 1) / 2;
    if (k <= max_black) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j) % 2 == 0 && x < k) {
                    printf("L");
                    x++;
                } else {
                    printf("S");
                }
            }
            printf("\n");
        }
    } else {
        printf("NO\n");
    }
    return 0;
}

