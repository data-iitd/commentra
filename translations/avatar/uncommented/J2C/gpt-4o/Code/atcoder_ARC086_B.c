#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int m = 0;
    for (int i = 1; i < n; ++i) {
        if (fabs(a[m]) < fabs(a[i])) {
            m = i;
        }
    }

    char **r = (char **)malloc(n * n * sizeof(char *));
    int r_count = 0;

    for (int i = 0; i < n; ++i) {
        if ((a[m] >= 0) ^ (a[i] >= 0)) {
            r[r_count] = (char *)malloc(20 * sizeof(char)); // Allocate space for the string
            sprintf(r[r_count], "%d %d", m + 1, i + 1);
            r_count++;
        }
    }

    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            r[r_count] = (char *)malloc(20 * sizeof(char)); // Allocate space for the string
            sprintf(r[r_count], "%d %d", i, i + 1);
            r_count++;
        }
    } else {
        for (int i = n; i > 1; --i) {
            r[r_count] = (char *)malloc(20 * sizeof(char)); // Allocate space for the string
            sprintf(r[r_count], "%d %d", i, i - 1);
            r_count++;
        }
    }

    printf("%d\n", r_count);
    for (int i = 0; i < r_count; ++i) {
        printf("%s\n", r[i]);
        free(r[i]); // Free each allocated string
    }

    free(r); // Free the array of strings
    free(a); // Free the array of integers
    return 0;
}
