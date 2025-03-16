

#include <bits/stdc++.h>

using namespace std;

int main() {
    // Main function declaration

    int n, m;
    cin >> n >> m;

    set<int> bannedRows, bannedCols;

    for (int i = 0; i < m; i++) {
        // Reading banned cells and adding them to the respective sets

        int r, c;
        cin >> r >> c;
        if (r > 1 && r < n) bannedRows.insert(r);
        if (c > 1 && c < n) bannedCols.insert(c);
    }

    int answer = (n - 2) * 2;
    // Initializing answer as the total number of cells in the grid minus the banned cells
    answer -= bannedRows.size();
    // Subtracting the number of banned rows
    answer -= bannedCols.size();
    // Subtracting the number of banned columns

    if (n % 2!= 0) {
        // Special case when the number of rows is odd

        int mid = (n + 1) / 2;
        if (!bannedRows.count(mid) &&!bannedCols.count(mid)) {
            // If the middle cell is not banned, decrement the answer
            answer--;
        }
    }

    cout << answer << endl;
    // Writing the answer to the output stream

    return 0;
}

