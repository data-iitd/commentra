
// C code equivalent to the given Go code
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    float a[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        qsort(a, n, sizeof(float), cmpfunc);
    }

    float na[n - 2];
    for (int j = 2; j < n; j++) {
        na[j - 2] = a[j];
    }

    na[0] = (a[0] + a[1]) / 2;
    for (int k = 0; k < n - 2; k++) {
        a[k] = na[k];
    }

    printf("%f\n", a[0]);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(float *)a - *(float *)b);
}

// End of C code
