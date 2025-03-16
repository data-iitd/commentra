#include <stdio.h>

int main() {
    // Take the number of elements in the array as input
    int n;
    scanf("%d", &n);

    // Initialize an array 'arr' of size 'n' and fill it with integers taken as input
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize an array 'ans' of size 'n' with zeros
    int ans[n];
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
    }

    // Variable 'mx' stores the maximum element in the array
    int mx = arr[n - 1];

    // Iterate through the array from index 'n-2' to '0' in reverse order
    for (int i = n - 2; i >= 0; i--) {
        // Update the answer at current index 'i' based on the maximum element 'mx' and current element 'arr[i]'
        ans[i] = (mx - arr[i] + 1 > 0) ? (mx - arr[i] + 1) : 0;

        // If the current element 'arr[i]' is greater than the maximum element 'mx', update 'mx'
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    // Print the answer list
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
