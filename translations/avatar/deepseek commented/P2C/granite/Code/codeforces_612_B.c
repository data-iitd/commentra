

#include <stdio.h>

int main() {
    int n;  // Declare an integer variable `n` to store the length of the list `a`
    scanf("%d", &n);  // Read an integer input representing the length of the list `a`

    int a[n];  // Declare an array `a` of length `n` to store the elements of the list
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);  // Read an integer input representing the elements of the list `a`
    }

    int b[n];  // Declare an array `b` of length `n` to store the positions of the elements in `a`
    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i;  // Assign the index of each element in `a` to the corresponding position in `b`, adjusting for zero-based indexing
    }

    int res = 0;  // Declare an integer variable `res` to store the result
    for (int i = 1; i < n; i++) {
        res += abs(b[i] - b[i - 1]);  // Calculate the sum of absolute differences between the positions of consecutive elements in `b`
    }

    printf("%d", res);  // Print the result

    return 0;
}
