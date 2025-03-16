#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class FastReader {
public:
    FastReader() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
};

int main() {
    FastReader in;

    // Read the dimensions of the grid
    int n = in.nextInt(), m = in.nextInt();

    // Initialize sets to keep track of banned rows and columns
    set<int> bannedRows, bannedCols;

    // Read the banned rows and columns
    for (int i = 0; i < m; i++) {
        int r = in.nextInt();
        // Add to bannedRows if the row is within valid range
        if (r > 1 && r < n) bannedRows.insert(r);
        int c = in.nextInt();
        // Add to bannedCols if the column is within valid range
        if (c > 1 && c < n) bannedCols.insert(c);
    }

    // Calculate the initial answer based on the grid size
    int answer = (n - 2) * 2;
    // Subtract the number of banned rows and columns from the answer
    answer -= bannedRows.size();
    answer -= bannedCols.size();

    // If n is odd, check the middle row and column
    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        // If the middle row and column are not banned, decrement the answer
        if (bannedRows.find(mid) == bannedRows.end() && bannedCols.find(mid) == bannedCols.end()) {
            answer--;
        }
    }

    // Output the final answer
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
