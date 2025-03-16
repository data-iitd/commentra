#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int M[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &M[i]);
    }
    
    int m = 0;
    for (int j = 0; j < n; j++) {
        int p;
        for (p = 0; p < n; p++) {
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
    
    return 0;
}

// <END-OF-CODE>
