#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements `n` and the number of queries `k` from the standard input
    int n, k;
    scanf("%d %d", &n, &k);

    // Read a single string `v` from the standard input
    char *v = (char *)malloc(n + 1);
    scanf("%s", v);

    // Initialize a list `d` with two elements: "LEFT" and "RIGHT"
    char *d[] = {"LEFT", "RIGHT"};

    // Determine the direction based on the difference between `k` and `n-k`
    int f = k - 1 < n - k;

    // Determine the number of elements to be appended to the list `a`
    int m = min(k - 1, n - k);

    // Initialize an empty list `a`
    char **a = (char **)malloc(m * sizeof(char *));

    // Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
    for (int i = 0; i < m; i++) {
        a[i] = d[f];
    }

    // Iterate through the string `v` with a step of 2 times the value of `f`
    for (int i = 0; i < n; i += 2 * f) {
        // Append "PRINT <character>" and the corresponding direction to the list `a`
        a[m++] = (char *)malloc(16 * sizeof(char));
        sprintf(a[m - 1], "PRINT %c", v[i]);
        a[m++] = d[f];
    }

    // Print all the elements of the list `a`, except the last one, separated by newline characters
    for (int i = 0; i < m - 1; i++) {
        printf("%s\n", a[i]);
    }

    // Free the memory allocated to the list `a`
    for (int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
    free(v);

    return 0;
}

