#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // Read the number of elements in the list `r`
    
    int *r = (int *)malloc(n * sizeof(int));  // Dynamically allocate memory for the list `r`
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);  // Read the space-separated integers into the list `r`
    }

    int ans = abs(r[0]);  // Initialize `ans` to the absolute value of the first element in the list `r`

    // The for loop iterates over the range from 1 to `n` (exclusive)
    // For each iteration, it adds the absolute difference between the current element and the previous element in the list `r` to `ans`
    for (int i = 1; i < n; i++) {
        ans += abs(r[i] - r[i - 1]);
    }

    printf("%d\n", ans);  // Print the value of `ans`

    free(r);  // Free the allocated memory
    return 0;
}  // <END-OF-CODE>
