#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    char v[1001];
    char d[2][5] = {"LEFT", "RIGHT"};
    int f, m;
    char a[2002][100];
    int a_index = 0;

    // Read the number of elements `n` and the number of queries `k` from the standard input
    scanf("%d %d", &n, &k);

    // Read a single string `v` from the standard input
    scanf("%s", v);

    // Determine the direction based on the difference between `k` and `n-k`
    f = k - 1 < n - k;

    // Determine the number of elements to be appended to the list `a`
    m = (k - 1 < n - k) ? k - 1 : n - k;

    // Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
    for (int i = 0; i < m; i++) {
        strcpy(a[a_index++], d[!f]);
    }

    // Iterate through the string `v` with a step of 2 times the value of `f`
    for (int i = 0; i < n; i += 2 * f) {
        // Append "PRINT <character>" and the corresponding direction to the list `a`
        sprintf(a[a_index++], "PRINT %c", v[i]);
        strcpy(a[a_index++], d[f]);
    }

    // Print all the elements of the list `a`, except the last one, separated by newline characters
    for (int i = 0; i < a_index - 1; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}
