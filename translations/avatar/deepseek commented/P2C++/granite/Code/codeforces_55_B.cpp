
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rememberTheNumber(vector<long long> &nums, int i, vector<char> &operations, vector<long long> &ans) {
    // If the index i is greater than or equal to 3, return to limit recursion depth
    if (i >= 3) {
        return;
    }

    // Iterate over pairs of numbers to perform operations
    for (int j = 0; j < 4; j++) {
        for (int k = j + 1; k < 4; k++) {
            if (nums[j]!= -1 && nums[k]!= -1) {
                long long s = nums[j];
                nums[j] = -1;  // Mark the number as used
                long long t = nums[k];

                // Perform the operation based on the current operation symbol
                if (operations[i] == '+') {
                    nums[k] = s + t;
                } else if (operations[i] == '*') {
                    nums[k] = s * t;
                }

                // If it's the last operation and the result is smaller than the current minimum, update ans
                if (i == 2 && nums[k] < ans[0]) {
                    ans[0] = nums[k];
                }

                // Recursively call the function with updated parameters
                rememberTheNumber(nums, i + 1, operations, ans);

                // Restore the original numbers to try other combinations
                nums[j] = s;
                nums[k] = t;
            }
        }
    }
}

int main() {
    // Read input numbers and operations
    vector<long long> nums(4);
    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
    }
    vector<char> operations(3);
    for (int i = 0; i < 3; i++) {
        cin >> operations[i];
    }

    // Initialize the answer list with a large number
    vector<long long> ans = {10000000000000000000000000};

    // Call the function with initial parameters
    rememberTheNumber(nums, 0, operations, ans);

    // Print the smallest number found
    cout << ans[0] << endl;

    return 0;
}

