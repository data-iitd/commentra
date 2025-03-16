#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum number of occurrences of a number in the array
int solution(int n, vector<int>& a) {
    // Initialize a memo table to store the number of occurrences of each number
    vector<int> memo(1e5 + 2, 0);

    // Iterate through the array and update the memo table
    for (int num : a) {
        // Increment the memo table for the current number and the next two numbers
        memo[num]++;
        memo[num + 1]++;
        memo[num + 2]++;
    }

    // Initialize output variable to store the maximum number of occurrences found
    int out = 0;

    // Iterate through the memo table and update the output variable if a larger number is found
    for (int num : memo) {
        if (num > 0) {
            // Update the output variable with the maximum number found so far
            out = max(out, num);
        }
    }

    // Return the maximum number of occurrences found
    return out;
}

// Main function to read input and call the solution function
int main() {
    // Read the size of the array from the standard input
    int n;
    cin >> n;

    // Allocate memory for the array and read its elements from the standard input
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Call the solution function and print the result
    cout << solution(n, a) << endl;

    return 0;
}

// <END-OF-CODE>
