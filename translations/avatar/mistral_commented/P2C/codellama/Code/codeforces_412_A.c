#include <stdio.h>

int main() {
    // Read the number of elements `n` and the number of queries `k` from the standard input
    int n, k;
    scanf("%d %d", &n, &k);

    // Read a single string `v` from the standard input
    char v[1000];
    scanf("%s", v);

    // Initialize a list `d` with two elements: "LEFT" and "RIGHT"
    char d[2][6] = {"LEFT", "RIGHT"};

    // Determine the direction based on the difference between `k` and `n-k`
    int f = k - 1 < n - k;

    // Determine the number of elements to be appended to the list `a`
    int m = k - 1 < n - k ? k - 1 : n - k;

    // Initialize an empty list `a`
    char a[1000][1000];
    int i = 0;

    // Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
    for (i = 0; i < m; i++) {
        strcpy(a[i], d[!f]);
    }

    // Iterate through the string `v` with a step of 2 times the value of `f`
    for (i = 0; i < strlen(v); i += 2 * f) {
        // Append "PRINT <character>" and the corresponding direction to the list `a`
        sprintf(a[i + m], "PRINT %c", v[i]);
        strcpy(a[i + m + 1], d[f]);
    }

    // Print all the elements of the list `a`, except the last one, separated by newline characters
    for (i = 0; i < strlen(a) - 1; i++) {
        printf("%s\n", a[i]);
    }

    // Print the last element of the list `a`
    printf("%s", a[i]);

    // Print the end of the code
    printf("