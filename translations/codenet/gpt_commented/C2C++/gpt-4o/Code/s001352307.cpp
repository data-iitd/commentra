#include <iostream>
#include <vector>

using namespace std;

// Global variables to hold the weight limit (W) and number of items (N)
int W, N;
// Vector to store the input items with their weights and values
vector<pair<int, int>> input(1024);

int main() {
    int i, j;
    // Vector to store the maximum value and corresponding weight for each capacity
    vector<pair<int, int>> ans(1024, {0, 0});
    int t;

    // Infinite loop to process multiple test cases
    for(t = 0; ; t++) {
        // Initialize the ans and input arrays to zero for each test case
        for(i = 0; i < 1024; i++) {
            ans[i] = {0, 0}; // Maximum value and total weight for capacity i
            input[i] = {0, 0}; // Value and weight of item i
        }

        // Read the weight limit (W) and number of items (N)
        cin >> W >> N;
        // Break the loop if the weight limit is zero (end of input)
        if(W == 0)
            break;

        // Read the value and weight of each item
        for(i = 0; i < N; i++)
            scanf("%d,%d", &input[i].first, &input[i].second);

        // Dynamic programming to calculate the maximum value for each capacity
        for(i = 0; i < N; i++) {
            // Traverse the capacities in reverse to avoid overwriting results
            for(j = 1023; j >= input[i].second; j--) {
                // Check if including the current item increases the maximum value
                if(ans[j].first < input[i].first + ans[j - input[i].second].first) {
                    // Update the maximum value and corresponding weight
                    ans[j].first = input[i].first + ans[j - input[i].second].first;
                    ans[j].second = input[i].second + ans[j - input[i].second].second;
                }
            }
        }

        // Find the maximum value and corresponding weight for the exact weight limit
        for(j = 0; ans[W].first == ans[W - j - 1].first; j++);

        // Print the results for the current test case
        cout << "Case " << t + 1 << ":\n" << ans[W - j].first << "\n" << ans[W - j].second << "\n";
    }

    return 0; // Return success
} // <END-OF-CODE>
