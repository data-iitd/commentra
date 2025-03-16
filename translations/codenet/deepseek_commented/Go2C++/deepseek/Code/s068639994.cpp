#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

// Helper functions to find the minimum and maximum of two integers.
int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

// Main logic of the program.
void mainFn() {
    // Get the number of elements in the slice.
    int n;
    cin >> n;
    // Get the slice of integers.
    vector<int> ls(n);
    for (int i = 0; i < n; ++i) {
        cin >> ls[i];
    }
    // Create a reversed version of the slice.
    vector<int> lsRev(ls);
    reverse(lsRev.begin(), lsRev.end());
    // Sort the original slice in ascending order.
    sort(ls.begin(), ls.end());
    // Sort the reversed slice in descending order.
    sort(lsRev.begin(), lsRev.end(), greater<int>());

    // Initialize the answer variable.
    int ans = 0;
    // Loop through the slice to calculate the answer.
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Calculate p and q based on the current elements.
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate x and y based on p and q.
            int x = q - p;
            int y = q + p;

            // Find the left boundary using binary search.
            int l = distance(ls.begin(), lower_bound(ls.begin(), ls.end(), x + 1));
            // Find the right boundary using binary search.
            int r = n - distance(lsRev.begin(), lower_bound(lsRev.begin(), lsRev.end(), y));

            // Calculate the sum of valid pairs.
            int sum = r - l;
            // Adjust the sum if the current indices are within the range.
            if (i >= l && i < r) {
                --sum;
            }
            if (j >= l && j < r) {
                --sum;
            }
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
