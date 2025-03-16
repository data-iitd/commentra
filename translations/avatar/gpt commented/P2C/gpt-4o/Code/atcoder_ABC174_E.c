#include <stdio.h>

int check(int lis[], int n, int k, int mid) {
    // Initialize a loop to iterate through each element in the list
    for (int i = 0; i < n; i++) {
        // If the current element is divisible by mid, increment k
        if (lis[i] % mid == 0) {
            k += 1;
        }
        // Decrease k by the number of times mid fits into the current element
        k -= (lis[i] / mid);
    }
    // Return 1 (true) if k is non-negative, indicating the condition is satisfied
    return k >= 0;
}

int main() {
    // Read input values for n (number of elements) and k (threshold value)
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Read the list of integers
    int lis[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lis[i]);
    }

    // Initialize the binary search bounds
    int a = 1, b = lis[0];
    for (int i = 1; i < n; i++) {
        if (lis[i] > b) {
            b = lis[i];
        }
    }
    
    // Set the initial answer to the maximum value in the list
    int ans = b;

    // Perform binary search to find the optimal mid value
    while (a <= b) {
        // Calculate the mid value
        int mid = (a + b) / 2;
        // Check if the current mid value satisfies the condition using the check function
        if (check(lis, n, k, mid)) {
            // If it does, update the answer and narrow the search to the left half
            ans = mid;
            b = mid - 1;
        } else {
            // If it doesn't, narrow the search to the right half
            a = mid + 1;
        }
    }

    // Print the final answer
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
