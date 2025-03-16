#include <stdio.h>

int main() {
    // Step 1: Take the number of elements in the array as input
    int n;
    scanf("%d", &n);

    // Step 2: Take a space-separated string of integers as input and store them in an array
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Initialize an array `ans` of zeros with the same length as the input array
    int ans[n];
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
    }

    // Step 4: Initialize `mx` to the last element of the array `arr`
    int mx = arr[n - 1];

    // Step 5: Iterate from the second last element to the first element of the array `arr` in reverse order
    for (int i = n - 2; i >= 0; i--) {
        // Step 6: Calculate the value `max(0, mx - arr[i] + 1)` and assign it to the corresponding position in the `ans` array
        ans[i] = (mx - arr[i] + 1 > 0) ? (mx - arr[i] + 1) : 0;

        // Step 7: If the current element is greater than `mx`, update `mx` with the current element
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    // Step 8: Print the elements of the `ans` array
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
