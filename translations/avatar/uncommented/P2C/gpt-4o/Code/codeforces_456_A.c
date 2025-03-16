#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a; // Sort in descending order
}

int main() {
    int n;
    scanf("%d", &n);
    
    int **m = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        m[i] = malloc(2 * sizeof(int));
        scanf("%d %d", &m[i][0], &m[i][1]);
    }

    // Sort the array of pairs based on the first element in descending order
    qsort(m, n, sizeof(int *), compare);

    int *a = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i][1] > a[1]) {
            printf("Happy Alex\n");
            break;
        }
        a = m[i];
    }
    printf("Poor Alex\n");

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}

// <END-OF-CODE>
