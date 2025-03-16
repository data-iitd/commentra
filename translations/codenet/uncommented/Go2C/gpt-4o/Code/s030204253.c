#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    float *a = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }
    
    for (int i = 0; i + 1 < n; i++) {
        qsort(a, n, sizeof(float), compare);
        float *na = (float *)malloc((n - 2 + 1) * sizeof(float));
        for (int j = 2; j < n; j++) {
            na[j - 2] = a[j];
        }
        na[n - 2] = (a[0] + a[1]) / 2;
        free(a);
        a = na;
        n = n - 1; // Reduce the size of the array
    }
    
    printf("%f\n", a[0]);
    free(a);
    return 0;
}

// <END-OF-CODE>
