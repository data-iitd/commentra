#include <stdio.h>

int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);

    // Declare the array and the answer array
    int arr[n], ans[n];

    // Read the array elements from input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Set the maximum value to the last element of the array
    int mx = arr[n - 1];

    // Iterate through the array from the second last element to the first
    for (int i = n - 2; i >= 0; i--) {
        // Calculate the required value for ans[i] based on the difference from the maximum
        ans[i] = (mx - arr[i] + 1 > 0) ? (mx - arr[i] + 1) : 0;

        // Update the maximum value if the current element is greater than the current maximum
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    // Print the result array as space-separated values
    for (int i = 0; i < n; i++) {
        printf("%d", ans[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
