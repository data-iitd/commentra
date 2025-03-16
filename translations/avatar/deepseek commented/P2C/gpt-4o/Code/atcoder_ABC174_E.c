#include <stdio.h>

int check(int lis[], int n, int k, int mid) {
    // This function checks if it's possible to distribute the elements of lis
    // such that each element is at most mid and the total number of operations
    // does not exceed k.
    for (int i = 0; i < n; i++) {
        if (lis[i] % mid == 0) {  // If lis[i] is divisible by mid, increment k by 1.
            k += 1;
        }
        k -= lis[i] / mid;  // Subtract the number of elements that can be handled by mid from k.
    }
    return k >= 0;  // Return 1 (true) if k is non-negative, else 0 (false).
}

int main() {
    // Read the number of elements (n) and the initial value of k from input.
    int n, k;
    scanf("%d %d", &n, &k);

    // Read the list of integers from input.
    int lis[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lis[i]);
    }

    // Initialize the search range with 1 and the maximum value in the list.
    int a = 1, b = lis[0];
    for (int i = 1; i < n; i++) {
        if (lis[i] > b) {
            b = lis[i];  // Find the maximum value in the list.
        }
    }

    // Initialize the answer with the maximum value in the list.
    int ans = b;

    // Perform a binary search to find the maximum value of mid that satisfies the condition.
    while (a <= b) {
        int mid = (a + b) / 2;  // Calculate the middle value of the current search range.
        if (check(lis, n, k, mid)) {  // Check if the current mid value is valid.
            ans = mid;  // Update the answer to the current mid value.
            b = mid - 1;  // Adjust the upper bound of the search range.
        } else {
            a = mid + 1;  // Adjust the lower bound of the search range.
        }
    }

    // Print the result, which is the maximum value of mid that satisfies the condition.
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
