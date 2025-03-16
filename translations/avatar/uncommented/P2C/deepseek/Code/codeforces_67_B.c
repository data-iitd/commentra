#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int M[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &M[i]);
    }
    int m = 0;
    for (int j = 0; j < n; j++) {
        for (int p = 0; p < n; p++) {
            if (M[p] == 0) {
                printf("%d ", p + 1);
                break;
            }
        }
        for (int l = 0; l < p + 1 - k; l++) {
            M[l]--;
        }
        M[p]--;
    }
    printf("\n");
    return 0;
}
