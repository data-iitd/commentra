#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (abs(a[m]) < abs(a[i])) {
            m = i;
        }
    }
    int r_size = 0;
    char **r = (char **)malloc(n * n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        r[i] = (char *)malloc(20 * sizeof(char));
    }
    for (int i = 0; i < n; i++) {
        if (a[m] >= 0 ^ a[i] >= 0) {
            sprintf(r[r_size], "%d %d", m + 1, i + 1);
            r_size++;
        }
    }
    if (a[m] >= 0) {
        for (int i = 1; i < n; i++) {
            sprintf(r[r_size], "%d %d", i, i + 1);
            r_size++;
        }
    } else {
        for (int i = n; i > 1; i--) {
            sprintf(r[r_size], "%d %d", i, i - 1);
            r_size++;
        }
    }
    printf("%d\n", r_size);
    for (int i = 0; i < r_size; i++) {
        printf("%s\n", r[i]);
        free(r[i]);
    }
    free(r);
    return 0;
}
