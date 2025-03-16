#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

class FastReader {
public:
    FastReader() {
        cin.tie(0);
        ios::sync_with_stdio(false);
    }

    // Method to read the next token
    string next() {
        string token;
        cin >> token;
        return token;
    }

    // Method to read the next integer
    int nextInt() {
        int number;
        cin >> number;
        return number;
    }

    // Method to read the next long
    long nextLong() {
        long number;
        cin >> number;
        return number;
    }

    // Method to read the next double
    double nextDouble() {
        double number;
        cin >> number;
        return number;
    }

    // Method to read the next line
    string nextLine() {
        string line;
        getline(cin, line);
        return line;
    }
};

int main() {
    FastReader in;
    // Read the dimensions of the grid
    int n = in.nextInt();
    // Read the number of banned cells
    int m = in.nextInt();

    // Initialize sets to keep track of banned rows and columns
    unordered_set<int> bannedRows, bannedCols;

    // Read each banned cell and add it to the appropriate set if it's not on the border
    for (int i = 0; i < m; i++) {
        int r = in.nextInt();
        if (r > 1 && r < n) bannedRows.insert(r);
        int c = in.nextInt();
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
    cout << answer << '\n';

    return 0;
}
