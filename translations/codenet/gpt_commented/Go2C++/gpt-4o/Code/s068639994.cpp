#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer from input
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a vector of integers from input
vector<int> getIntVector(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = getInt();
    }
    return vec;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Main function containing the core logic of the program
void mainFn() {
    // Read the number of elements
    int n = getInt();
    // Read the integer vector from input
    vector<int> ls = getIntVector(n);
    // Create a reversed copy of the original vector
    vector<int> lsRev = ls;
    // Sort the original vector in ascending order
    sort(ls.begin(), ls.end());
    // Sort the reversed vector in descending order
    sort(lsRev.rbegin(), lsRev.rend());

    // Initialize the answer variable
    long long ans = 0;
    // Iterate through all pairs of elements in the sorted vector
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Determine the minimum and maximum of the two selected elements
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate the differences and sums needed for searching
            int x = q - p;
            int y = q + p;

            // Find the left boundary for elements greater than x
            int l = lower_bound(ls.begin(), ls.end(), x + 1) - ls.begin();
            // Find the right boundary for elements less than y
            int r = n - (upper_bound(lsRev.begin(), lsRev.end(), y - 1) - lsRev.begin());

            // Calculate the number of valid elements in the range
            int sum = r - l;
            // Adjust the count if the current indices are within the range
            if (i >= l && i < r) sum--;
            if (j >= l && j < r) sum--;
            // Ensure the sum is non-negative
            sum = max(0, sum);
            // Accumulate the result
            ans += sum;
        }
    }

    // Divide the final answer by 3 as per the problem requirements
    ans /= 3;
    // Output the result
    cout << ans << endl;
}

// Entry point of the program
int main() {
    // Call the main function to execute the logic
    mainFn();
    return 0;
}

// <END-OF-CODE>
