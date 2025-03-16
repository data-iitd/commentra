#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void rememberTheNumber(vector<int>& nums, int i, vector<char>& operations, vector<long long>& ans) {
    if (i >= 3) {
        return; // If the index 'i' is greater than or equal to 3, return.
    }

    for (int j = 0; j < 4; j++) {
        for (int k = j + 1; k < 4; k++) {
            if (nums[j] != -1 && nums[k] != -1) { // Check if both numbers are not -1
                int s = nums[j]; // Store the value of nums[j]
                nums[j] = -1; // Mark nums[j] as processed
                int t = nums[k]; // Store the value of nums[k]

                if (operations[i] == '+') {
                    nums[k] = s + t; // Perform addition
                } else if (operations[i] == '*') {
                    nums[k] = s * t; // Perform multiplication
                }

                if (i == 2 && nums[k] < ans[0]) {
                    ans[0] = nums[k]; // Update the answer if conditions are met
                }

                rememberTheNumber(nums, i + 1, operations, ans); // Recursive call

                nums[j] = s; // Restore the original value of nums[j]
                nums[k] = t; // Restore the original value of nums[k]
            }
        }
    }
}

int main() {
    vector<int> nums(4);
    for (int i = 0; i < 4; i++) {
        cin >> nums[i]; // Read the list of numbers
    }

    vector<char> operations(3);
    for (int i = 0; i < 3; i++) {
        cin >> operations[i]; // Read the list of operations
    }

    vector<long long> ans(1, numeric_limits<long long>::max()); // Initialize the answer with a large number
    rememberTheNumber(nums, 0, operations, ans); // Call the function with initial index 0

    cout << ans[0] << endl; // Print the final answer
    return 0;
}

// <END-OF-CODE>
