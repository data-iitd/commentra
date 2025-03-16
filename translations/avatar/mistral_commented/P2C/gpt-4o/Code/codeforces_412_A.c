#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    // Read the number of elements `n` and the number of queries `k`
    scanf("%d %d", &n, &k);

    // Read a single string `v`
    char v[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", v);

    // Initialize an array of directions
    const char *d[] = {"LEFT", "RIGHT"};

    // Determine the direction based on the difference between `k` and `n-k`
    int f = (k - 1) < (n - k);

    // Determine the number of elements to be appended to the list `a`
    int m = (k - 1) < (n - k) ? (k - 1) : (n - k);

    // Initialize an array to store the output
    char a[200001][50]; // Assuming a maximum of 200000 entries and each entry can be up to 49 characters + null terminator
    int index = 0;

    // Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
    for (int i = 0; i < m; i++) {
        strcpy(a[index++], d[!f]);
    }

    // Iterate through the string `v` with a step of 2 times the value of `f`
    for (int i = 0; i < strlen(v); i += 2 * f) {
        // Append "PRINT <character>" and the corresponding direction to the list `a`
        sprintf(a[index++], "PRINT %c", v[i]);
        strcpy(a[index++], d[f]);
    }

    // Print all the elements of the list `a`, except the last one, separated by newline characters
    for (int i = 0; i < index - 1; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}

// <END-OF-CODE>
