#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int func(int *A, int *size) {
    int min = 0;
    int newSize = 0;
    for (int i = 0; i < *size; i++) {
        if (A[i] == 0) {
            continue; // Skip zero
        } else {
            if (min != 0) {
                A[newSize] = A[i] % min;
                if (A[newSize] == 1) {
                    printf("1\n");
                    exit(0);
                }
            } else {
                min = A[i];
                A[newSize] = A[i];
            }
            newSize++;
        }
    }
    *size = newSize; // Update the size of the array
    qsort(A, *size, sizeof(int), compare); // Sort the array
    return newSize;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    
    if (n == 1) {
        scanf("%d", &a[0]);
        printf("%d\n", a[0]);
        free(a);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare); // Sort the array

    if (a[n - 1] == 0) {
        printf("0\n");
        free(a);
        return 0;
    }

    int ans = 0;
    while (1) {
        if (n == 1) {
            ans = a[0];
            break;
        }
        n = func(a, &n); // Update n with the new size after func
    }

    printf("%d\n", ans);
    free(a);
    return 0;
}

// <END-OF-CODE>
