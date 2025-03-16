#include <iostream>

// Global variables to hold the weight limit (W) and number of items (N)
int W, N;
// Array to store the input items with their weights and values
int input[1024][2];

int main() {
    int i, j;
    // Array to store the maximum value and corresponding weight for each capacity
    int ans[1024][2];
    int t;

    // Infinite loop to process multiple test cases
    for(t = 0; ; t++) {
        // Initialize the ans and input arrays to zero for each test case
        for(i = 0; i < 1024; i++) {
            ans[i][0] = 0; // Maximum value for capacity i
            ans[i][1] = 0; // Total weight for maximum value
            input[i][0] = 0; // Value of item i
            input[i][1] = 0; // Weight of item i
        }

        // Read the weight limit (W) and number of items (N)
        std::cin >> W >> N;
        // Break the loop if the weight limit is zero (end of input)
        if(W == 0)
            break;

        // Read the value and weight of each item
        for(i = 0; i < N; i++)
            std::cin >> input[i][0] >> input[i][1];

        // Dynamic programming to calculate the maximum value for each capacity
        for(i = 0; i < N; i++) {
            // Traverse the capacities in reverse to avoid overwriting results
            for(j = 1023; j >= input[i][1]; j--) {
                // Check if including the current item increases the maximum value
                if(ans[j][0] < input[i][0] + ans[j - input[i][1]][0]) {
                    // Update the maximum value and corresponding weight
                    ans[j][0] = input[i][0] + ans[j - input[i][1]][0];
                    ans[j][1] = input[i][1] + ans[j - input[i][1]][1];
                }
            }
        }

        // Find the maximum value and corresponding weight for the exact weight limit
        for(j = 0; ans[W][0] == ans[W - j - 1][0]; j++);

        // Print the results for the current test case
        std::cout << "Case " << t + 1 << ":\n" << ans[W - j][0] << "\n" << ans[W - j][1] << "\n";
    }

    return 0; // Return success
}

