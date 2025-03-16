#include <stdio.h>

void solve() {
    int t;
    scanf("%d", &t); // Read the number of test cases
    int arr[t]; // Initialize an array to store the elements
    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]); // Read the elements of the array
    }
    
    int prevWinner = 0; // Initialize the previous winner variable
    for (int i = 0; i < t; i++) {
        if (arr[i] == 1) { // Check if the current element is 1
            if (prevWinner == 0) { // If no previous winner, set the winner to 2
                prevWinner = 2;
            }
        }
        if (prevWinner == 2 || prevWinner == 0) { // Check if the previous winner is 2 or unset
            if ((arr[i] - 1) % 2 == 0) { // Check if the condition for player 2 is met
                printf("2\n"); // Print the winner
                prevWinner = 2; // Update the previous winner
            } else {
                printf("1\n"); // Print the winner
                prevWinner = 1; // Update the previous winner
            }
        } else { // If the previous winner is 1
            if ((arr[i] - 1) % 2 == 0) { // Check if the condition for player 1 is met
                printf("1\n"); // Print the winner
                prevWinner = 1; // Update the previous winner
            } else {
                printf("2\n"); // Print the winner
                prevWinner = 2; // Update the previous winner
            }
        }
    }
}

int main() {
    int t = 1; // Number of test cases
    while (t-- > 0) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
