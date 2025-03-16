#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n; // Read the number of elements
    cin >> d; // Read the difference threshold
    vector<int> nums(n); // Initialize a vector to store the numbers

    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // Read the numbers and store them in the vector
    }

    int result = 0; // Initialize the result variable to 0
    int a = 0; // Initialize another variable to store the difference

    for (int i = 1; i < n; i++) {
        a = (nums[i - 1] - nums[i]); // Calculate the difference between consecutive elements
        if (a >= 0) {
            result += a / d + 1; // Update the result based on the difference
            nums[i] += (a / d + 1) * d; // Adjust the current element to meet the condition
        }
    }

    cout << result << endl; // Print the final result
    return 0;
}

// <END-OF-CODE>
