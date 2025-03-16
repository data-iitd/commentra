#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of rows (n) from user input
    int n;
    cin >> n;

    // Read n rows of integers into a 2D vector (matrix) m
    vector<vector<int>> m(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> m[i][0] >> m[i][1];
    }

    // Sort the matrix m in descending order based on the first element of each row
    sort(m.begin(), m.end(), greater<vector<int>>());

    // Initialize a variable a with the first row of the sorted matrix
    vector<int> a = m[0];

    // Iterate through the remaining rows of the sorted matrix
    for (size_t i = 1; i < m.size(); ++i) {
        // Check if the second element of the current row is greater than the second element of the previous row
        if (m[i][1] > a[1]) {
            // If true, print 'Happy Alex' and exit the loop
            cout << "Happy Alex" << endl;
            break;
        }
        // Update a to the current row for the next iteration
        a = m[i];
    }
    // If the loop completes without finding a greater second element, print 'Poor Alex'
    if (a[1] <= m.back()[1]) {
        cout << "Poor Alex" << endl;
    }

    return 0;
}
// <END-OF-CODE>
