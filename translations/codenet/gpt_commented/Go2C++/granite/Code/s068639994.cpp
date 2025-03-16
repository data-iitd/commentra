
#include <bits/stdc++.h>
using namespace std;

// mainFn contains the core logic of the program
void mainFn() {
    // Read the number of elements
    int n;
    cin >> n;
    // Read the integer slice from input
    vector<int> ls(n);
    for (int i = 0; i < n; i++) {
        cin >> ls[i];
    }
    // Create a reversed copy of the original slice
    vector<int> lsRev = ls;
    reverse(lsRev.begin(), lsRev.end());
    // Sort the original slice in ascending order
    sort(ls.begin(), ls.end());
    // Sort the reversed slice in descending order
    sort(lsRev.begin(), lsRev.end());

    // Initialize the answer variable
    int ans = 0;
    // Iterate through all pairs of elements in the sorted slice
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Determine the minimum and maximum of the two selected elements
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate the differences and sums needed for searching
            int x = q - p;
            int y = q + p;

            // Find the left boundary for elements greater than x
            int l = lower_bound(ls.begin(), ls.end(), x) - ls.begin();
            // Find the right boundary for elements less than y
            int r = n - (upper_bound(lsRev.begin(), lsRev.end(), y) - lsRev.begin());

            // Calculate the number of valid elements in the range
            int sum = r - l;
            // Adjust the count if the current indices are within the range
            if ((i >= l) && (i <= r)) {
                sum--;
            }
            if ((j >= l) && (j <= r)) {
                sum--;
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

int main() {
    // Call the main function to execute the logic
    mainFn();
    return 0;
}

// min returns the smaller of two integers
int min(int a, int b) {
    return a < b? a : b;
}

// max returns the larger of two integers
int max(int a, int b) {
    return a > b? a : b;
}

// -----------------------------------------

// Global variables for input and output handling
//... (same as in the given Go code)

// getInt reads an integer from input
int getInt() {
    //... (same as in the given Go code)
}

// getIntSlice reads a slice of integers from input
vector<int> getIntSlice(int n) {
    //... (same as in the given Go code)
}

// getString reads a string from input
string getString() {
    //... (same as in the given Go code)
}

// puts writes the given arguments to the output
void puts(vector<string> a) {
    //... (same as in the given Go code)
}

// puts writes the given arguments to the output
void puts(int a) {
    //... (same as in the given Go code)
}

// puts writes the given arguments to the output
void puts(string a) {
    //... (same as in the given Go code)
}

// puts writes the given arguments to the output
void puts(char a) {
    //... (same as in the given Go code)
}

// puts writes the given arguments to the output
void puts() {
    //... (same as in the given Go code)
}