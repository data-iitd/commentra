
#include <stdio.h>

int main() {
    // Read the number of elements `n` and the number of queries `k` from the standard input
    int n, k;
    scanf("%d %d", &n, &k);

    // Read a single string `v` from the standard input
    char v[1000];
    scanf("%s", v);

    // Initialize a list `d` with two elements: "LEFT" and "RIGHT"
    char *d[] = {"LEFT", "RIGHT"};

    // Determine the direction based on the difference between `k` and `n-k`
    int f = k - 1 < n - k;

    // Determine the number of elements to be appended to the list `a`
    int m = k - 1 < n - k? k - 1 : n - k;

    // Initialize an empty list `a`
    char *a[1000];

    // Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
    for (int i = 0; i < m; i++) {
        a[i] = d[not f];
    }

    // Iterate through the string `v` with a step of 2 times the value of `f`
    for (int i = 0; i < strlen(v); i += 2 * f) {
        // Append "PRINT <character>" and the corresponding direction to the list `a`
        char print[100];
        sprintf(print, "PRINT %c", v[i]);
        a[m + i / (2 * f)] = print;
        a[m + i / (2 * f) + 1] = d[f];
    }

    // Print all the elements of the list `a`, except the last one, separated by newline characters
    for (int i = 0; i < m + (strlen(v) / (2 * f)); i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}
