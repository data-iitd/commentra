#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of cells (n) and the target cell (t)
    int n, t;
    cin >> n >> t;

    // Read the list of cells that can be jumped from each cell
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // Initialize the current cell to 1 (1-based index)
    int current_cell = 1;

    // Loop until the current cell exceeds the target cell
    while (current_cell <= t) {
        // Update the current cell by adding the value of the cell it's currently on
        current_cell += s[current_cell - 1];

        // Check if the current cell is the target cell
        if (current_cell == t) {
            // If yes, print "YES" and exit the program
            cout << "YES" << endl;
            return 0;
        }
    }

    // If the loop finishes without finding the target cell, print "NO"
    cout << "NO" << endl;

    return 0;
}

// <END-OF-CODE>
