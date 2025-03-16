#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to get the minimum of two integers.
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to get the maximum of two integers.
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Main function containing the logic of the program.
void mainFn() {
    // Get the number of elements in the vector.
    int n;
    cin >> n;

    // Get the vector of integers.
    vector<int> ls(n);
    for (int i = 0; i < n; i++) {
        cin >> ls[i];
    }

    // Create a reversed version of the vector.
    vector<int> lsRev = ls;

    // Sort the original vector in ascending order.
    sort(ls.begin(), ls.end());

    // Sort the reversed vector in descending order.
    sort(lsRev.rbegin(), lsRev.rend());

    // Initialize the answer variable.
    long long ans = 0;

    // Loop through the vector to calculate the answer.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate p and q based on the current elements.
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate x and y based on p and q.
            int x = q - p;
            int y = q + p;

            // Find the left boundary using binary search.
            int l = lower_bound(ls.begin(), ls.end(), x + 1) - ls.begin();
            // Find the right boundary using binary search.
            int r = n - (upper_bound(lsRev.begin(), lsRev.end(), y) - lsRev.begin());

            // Calculate the sum of valid pairs.
            int sum = r - l;
            // Adjust the sum if the current indices are within the range.
            if (i >= l && i < r) sum--;
            if (j >= l && j < r) sum--;
            // Ensure the sum is not negative.
            sum = max(0, sum);
            // Add the sum to the answer.
            ans += sum;
        }
    }

    // Divide the answer by 3 to get the final result.
    ans /= 3;
    // Print the final answer.
    cout << ans << endl;
}

// Main function to initialize the program.
int main() {
    mainFn();
    return 0;
}

// <END-OF-CODE>
