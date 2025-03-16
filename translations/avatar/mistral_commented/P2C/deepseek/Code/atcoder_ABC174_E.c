#include <stdio.h>
#include <limits.h>

// Function to check if 'k' is positive after checking all elements in 'lis' with mid as divisor
int check(int lis[], int n, int k, int mid) {
    // Iterate through each element in the list 'lis'
    for (int i = 0; i < n; i++) {
        // If the element 'i' is divisible by 'mid', increment 'k'
        if (lis[i] % mid == 0) {
            k += 1;
        }
        // Subtract the quotient of 'i' and 'mid' from 'k'
        k -= (lis[i] / mid);
    }
    // Return 1 if 'k' is still positive after the loop, else 0
    return k >= 0;
}

int main() {
    int n, k;

    // Take input of 'n' and 'k'
    scanf("%d %d", &n, &k);

    // Take input of 'n' number of elements in the list 'lis' and store them in an array
    int lis[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lis[i]);
    }

    // Initialize the variables 'a' and 'b' with minimum and maximum values respectively
    int a = 1, b = INT_MIN;

    // Find the maximum value in 'lis' to initialize 'b'
    for (int i = 0; i < n; i++) {
        if (lis[i] > b) {
            b = lis[i];
        }
    }

    // Initialize the variable 'ans' with the maximum value of 'b'
    int ans = b;

    // Binary search algorithm to find the answer
    while (a <= b) {
        // Calculate the middle value of 'a' and 'b'
        int mid = (a + b) / 2;
        // Check if 'k' is positive after checking all elements in 'lis' with 'mid' as divisor
        if (check(lis, n, k, mid)) {
            // Update the answer if the condition is true
            ans = mid;
            // Update the upper limit of the binary search 'b'
            b = mid - 1;
        } else {
            // Update the lower limit of the binary search 'a'
            a = mid + 1;
        }
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}
