#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

using namespace std;

vector<int> getPoints(int n, int k, int l, int r, int sAll, int sk) {
    vector<int> ans(n, l); // Initialize all points with score l

    // Calculate the remaining score after removing the given k points and segments of length l
    sAll -= sk + (n - k) * l;

    // Remove the score of the given k points
    sk -= k * l;

    // Find the indices of the points to be increased in the first while loop
    int idx = n - 1;
    while (sk > 0 && idx >= n - k) {
        ans[idx--]++; // Increase the score of the current point by 1
        sk--; // Decrease the remaining score by 1
    }

    // Find the indices of the points to be increased in the second while loop
    while (sAll > 0) {
        idx = 0;
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++; // Increase the score of the current point by 1
            sAll--; // Decrease the remaining score by 1
        }
    }

    // Return the updated scores of all points
    return ans;
}

int main() {
    int n, k, l, r, sAll, sk;
    cin >> n >> k >> l >> r >> sAll >> sk;

    // Call the getPoints() function to get the updated scores of all points
    vector<int> ans = getPoints(n, k, l, r, sAll, sk);

    // Print the updated scores of all points
    for (int num : ans) {
        cout << num << " "; // Print each updated score followed by a space
    }
    cout << endl; // Print a newline after printing all scores

    return 0;
}

