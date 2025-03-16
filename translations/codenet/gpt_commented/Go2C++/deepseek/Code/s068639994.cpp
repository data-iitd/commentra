#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

// Helper function to read integers from input
int readInt() {
    int n;
    cin >> n;
    return n;
}

// Helper function to read a vector of integers from input
vector<int> readIntVector(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    return vec;
}

// Main function containing the core logic
void mainFn() {
    // Read the number of elements
    int n = readInt();
    // Read the integer slice from input
    vector<int> ls = readIntVector(n);
    // Create a reversed copy of the original vector
    vector<int> lsRev(ls);
    // Sort the original vector in ascending order
    sort(ls.begin(), ls.end());
    // Sort the reversed vector in descending order
    sort(lsRev.begin(), lsRev.end(), greater<int>());

    // Initialize the answer variable
    int ans = 0;
    // Iterate through all pairs of elements in the sorted vector
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Determine the minimum and maximum of the two selected elements
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate the differences and sums needed for searching
            int x = q - p;
            int y = q + p;

            // Find the left boundary for elements greater than x
            int l = distance(ls.begin(), lower_bound(ls.begin(), ls.end(), x, greater<int>()));
            // Find the right boundary for elements less than y
            int r = n - distance(lsRev.begin(), lower_bound(lsRev.begin(), lsRev.end(), y));

            // Calculate the number of valid elements in the range
            int sum = r - l;
            // Adjust the count if the current indices are within the range
            if ((i >= l) && (i <= r)) {
                --sum;
            }
            if ((j >= l) && (j <= r)) {
                --sum;
            }
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

// Main function to execute the program
int main() {
    // Call the main function to execute the logic
    mainFn();
    return 0;
}
