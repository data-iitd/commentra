#include <stdio.h>

void solve() {
    int t;
    scanf("%d", &t); // Read the number of elements in the array
    int arr[t]; // Declare the array

    // Populate the array with input values
    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
    }

    int prevWinner = 0; // Variable to track the previous winner

    // Iterate through the array to determine the winner for each element
    for (int i = 0; i < t; i++) {
        // Check if the current element is 1
        if (arr[i] == 1) {
            // If the previous winner is 0, set the previous winner to 2
            if (prevWinner == 0) {
                prevWinner = 2;
            }
        }

        // Determine the winner based on the previous winner and the current element
        if (prevWinner == 2 || prevWinner == 0) {
            // If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0) {
                printf("2\n"); // Print winner 2
                prevWinner = 2; // Update previous winner
            } else {
                printf("1\n"); // Print winner 1
                prevWinner = 1; // Update previous winner
            }
        } else {
            // If the previous winner is 1, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0) {
                printf("1\n"); // Print winner 1
                prevWinner = 1; // Update previous winner
            } else {
                printf("2\n"); // Print winner 2
                prevWinner = 2; // Update previous winner
            }
        }
    }
}

int main() {
    int t = 1; // Number of test cases (currently set to 1)
    while (t-- > 0) {
        solve(); // Call the solve function for processing
    }
    return 0;
}

// <END-OF-CODE>
