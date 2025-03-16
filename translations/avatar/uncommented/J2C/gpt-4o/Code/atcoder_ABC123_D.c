#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to compare two long integers for qsort
int compare(const void *a, const void *b) {
    return (*(long *)b - *(long *)a; // Sort in descending order
}

int main() {
    int x[3];
    int max = 0;
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        if (x[i] > max) {
            max = x[i];
        }
    }
    
    int k;
    scanf("%d", &k);
    
    long *a[3];
    for (int i = 0; i < 3; ++i) {
        a[i] = (long *)malloc(x[i] * sizeof(long));
        for (int j = 0; j < x[i]; ++j) {
            scanf("%ld", &a[i][j]);
        }
        qsort(a[i], x[i], sizeof(long), compare); // Sort each list
    }
    
    long *ans = (long *)malloc(MAX_SIZE * sizeof(long)); // Assuming a maximum size for ans
    int ans_size = 0;

    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    long tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    ans[ans_size++] = tmp;
                }
            }
        }
    }

    qsort(ans, ans_size, sizeof(long), compare); // Sort the results

    for (int i = 0; i < k && i < ans_size; ++i) {
        printf("%ld\n", ans[i]);
    }

    // Free allocated memory
    for (int i = 0; i < 3; ++i) {
        free(a[i]);
    }
    free(ans);

    return 0;
}

// <END-OF-CODE>
