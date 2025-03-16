#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);

    int a[x], b[y], c[z];
    for (int i = 0; i < x; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < y; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < z; i++) {
        scanf("%d", &c[i]);
    }

    int ab[x * y];
    int ab_index = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab[ab_index++] = a[i] + b[j];
        }
    }

    for (int i = 0; i < ab_index; i++) {
        for (int j = i + 1; j < ab_index; j++) {
            if (ab[i] < ab[j]) {
                int temp = ab[i];
                ab[i] = ab[j];
                ab[j] = temp;
            }
        }
    }

    int abc[k * z];
    int abc_index = 0;
    for (int i = 0; i < (k < ab_index ? k : ab_index); i++) {
        for (int j = 0; j < z; j++) {
            abc[abc_index++] = ab[i] + c[j];
        }
    }

    for (int i = 0; i < abc_index; i++) {
        for (int j = i + 1; j < abc_index; j++) {
            if (abc[i] < abc[j]) {
                int temp = abc[i];
                abc[i] = abc[j];
                abc[j] = temp;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%d\n", abc[i]);
    }

    return 0;
}
