

#include <stdio.h>

int main() {
    int n;  // Declare an integer variable `n` to store the number of elements in the list `r`
    scanf("%d", &n);  // Read the number of elements in the list `r` and store it in the variable `n`

    int r[n];  // Declare an integer array `r` of size `n` to store the elements of the list `r`
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);  // Read the space-separated string of integers and store them in the array `r`
    }

    int ans = abs(r[0]);  // Initialize `ans` to the absolute value of the first element in the array `r`

    // The for loop iterates over the range from 1 to `n` (inclusive)
    // For each iteration, it adds the absolute difference between the current element and the previous element in the array `r` to `ans`
    for (int i = 1; i < n; i++) {
        ans += abs(r[i] - r[i - 1]);
    }

    printf("%d\n", ans);  // Print the value of `ans`

    return 0;
}

