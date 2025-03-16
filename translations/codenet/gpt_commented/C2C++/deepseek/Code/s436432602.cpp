#include <iostream>
#include <vector>
#include <cstdlib>

// Function to determine the winner of the game
void run(void) {
    int n, k; // Declare variables for the number of elements and the target value
    // Read the number of elements and the target value from input
    std::cin >> n >> k;
    
    std::vector<int> a(n); // Vector to store the elements
    int i; // Loop variables

    // Read the elements into the vector
    for(i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Allocate memory for the dynamic programming array
    std::vector<int> dp(k + 1, 0);

    // Iterate over each possible value from 1 to k
    for(i = 1; i <= k; i++) {
        bool win = false; // Variable to determine if the current player can win

        // Check each element to see if it can lead to a winning position
        for(int j = 0; j < n && a[j] <= i; j++) {
            // If there exists a move that leads to a losing position for the opponent
            if(dp[i - a[j]] == 0) {
                win = true; // Current player can win
            }
        }
        
        // Store the result in the dp array: 1 if the current player can win, 0 otherwise
        dp[i] = win ? 1 : 0;
    }

    // Output the result: "First" if the first player can win, otherwise "Second"
    std::cout << (dp[k] ? "First" : "Second") << std::endl;
}

// Main function to execute the program
int main(void) {
    run(); // Call the run function to execute the game logic
    return 0; // Return success
}

