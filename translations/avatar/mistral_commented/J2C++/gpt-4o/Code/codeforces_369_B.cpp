#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic array manipulation
#include <algorithm> // Including the algorithm library for array manipulation functions

using namespace std;

vector<int> getPoints(int n, int k, int l, int r, int sAll, int sk) {
    vector<int> ans(n, l); // Initializing a vector ans of size n with all elements set to l

    // Calculating the remaining score after removing the given k points and segments of length l
    sAll -= sk + (n - k) * l;

    // Removing the score of the given k points
    sk -= k * l;

    // Finding the indices of the points to be increased in the first while loop
    int idx = n - 1;
    while (sk > 0 && idx >= n - k) {
        ans[idx--]++; // Increasing the score of the current point by 1
        sk--; // Decreasing the remaining score by 1
    }

    // Finding the indices of the points to be increased in the second while loop
    while (sAll > 0) {
        idx = 0;
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++; // Increasing the score of the current point by 1
            sAll--; // Decreasing the remaining score by 1
        }
    }

    // Returning the updated scores of all points as a vector
    return ans;
}

int main() {
    int n, k, l, r, sAll, sk; // Declaring variables for input

    // Reading input values from the user
    cin >> n >> k >> l >> r >> sAll >> sk; // Reading the number of points n, number of points to be removed k, length l, radius r, total score sAll, and score sk

    // Calling the getPoints() function to get the updated scores of all points
    vector<int> ans = getPoints(n, k, l, r, sAll, sk);

    // Printing the updated scores of all points
    for (int num : ans) {
        cout << num << " "; // Printing each updated score followed by a space
    }

    cout << endl; // Printing a newline after printing all scores
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
