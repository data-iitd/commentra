
#include <stdio.h>

int main() {
    int n, k, M[100], m, j, p, l;
    scanf("%d %d", &n, &k);
    for (j = 0; j < n; j++) {
        scanf("%d", &M[j]);
    }
    for (p = 0; p < n; p++) {
        if (M[p] == 0) {
            printf("%d ", p + 1);
            break;
        }
    }
    for (l = 0; l < p + 1 - k; l++) {
        M[l] -= 1;
    }
    M[p] -= 1;
    return 0;
}
//END-OF-CODE