#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define INF_INT64 LLONG_MAX
#define INF_INT32 INT_MAX

void readInt3(int *a, int *b, int *c) {
    scanf("%d %d %d", a, b, c);
}

int* duplicatePatterns(int *elems, int k, int *size) {
    int totalPatterns = pow(4, k);
    int *patterns = (int *)malloc(totalPatterns * k * sizeof(int));
    *size = totalPatterns;

    for (int i = 0; i < totalPatterns; i++) {
        for (int j = 0; j < k; j++) {
            patterns[i * k + j] = elems[(i / (int)pow(4, j)) % 4];
        }
    }
    return patterns;
}

int main() {
    int a, b, c, k;
    readInt3(&a, &b, &c);
    scanf("%d", &k);

    int elems[] = {0, 1, 2, 3};
    int size;
    int *patterns = duplicatePatterns(elems, k, &size);

    for (int i = 0; i < size; i++) {
        int r = a, g = b, b_val = c;
        for (int j = 0; j < k; j++) {
            if (patterns[i * k + j] == 0) {
                continue;
            } else if (patterns[i * k + j] == 1) {
                r *= 2;
            } else if (patterns[i * k + j] == 2) {
                g *= 2;
            } else if (patterns[i * k + j] == 3) {
                b_val *= 2;
            }
        }

        if (g > r && b_val > g) {
            printf("Yes\n");
            free(patterns);
            return 0;
        }
    }
    printf("No\n");
    free(patterns);
    return 0;
}

/* <END-OF-CODE> */
