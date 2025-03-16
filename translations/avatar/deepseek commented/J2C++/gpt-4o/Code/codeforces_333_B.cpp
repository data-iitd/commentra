#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    // Fast input
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the dimensions of the grid
    int n, m;
    cin >> n >> m;

    // Initialize sets to keep track of banned rows and columns
    set<int> bannedRows, bannedCols;

    // Read each banned cell and add it to the appropriate set if it's not on the border
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        if (r > 1 && r < n) bannedRows.insert(r);
        if (c > 1 && c < n) bannedCols.insert(c);
    }

    // Calculate the number of cells that can be reached, accounting for banned rows and columns
    int answer = (n - 2) * 2;
    answer -= bannedRows.size();
    answer -= bannedCols.size();

    // Adjust the answer if the grid size is odd and the center cell is not banned
    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        if (bannedRows.find(mid) == bannedRows.end() && bannedCols.find(mid) == bannedCols.end()) {
            answer--;
        }
    }

    // Output the final answer
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
