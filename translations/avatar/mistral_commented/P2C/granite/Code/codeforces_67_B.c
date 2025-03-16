
#include <stdio.h>

int main() {
    int n, k, M[100], m = 0;
    scanf("%d %d", &n, &k);
    for (int j = 0; j < n; j++) {
        scanf("%d", &M[j]);
    }
    for (int j = 0; j < n; j++) {
        for (int p = 0; p < n; p++) {
            if (M[p] == 0) {
                printf("%d ", p + 1);
                m++;
                break;
            }
        }
        for (int l = 0; l < p + 1 - k; l++) {
            M[l]--;
        }
        M[p]--;
    }
    return 0;
}
