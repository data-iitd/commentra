#include <bits/stdc++.h>
using namespace std;

// FastReader class to read input efficiently
class FastReader {
    public:
    FastReader() {
        // nothing to do here
    }

    // Method to read the next token
    string next() {
        string s;
        getline(cin, s);
        return s;
    }

    // Method to read the next integer
    int nextInt() {
        return stoi(next());
    }

    // Method to read the next long integer
    long long nextLong() {
        return stoll(next());
    }

    // Method to read the next float
    float nextFloat() {
        return stof(next());
    }

    // Method to read the next double
    double nextDouble() {
        return stod(next());
    }

    // Method to read the next line
    string nextLine() {
        string s;
        getline(cin, s);
        return s;
    }
};

// Main function
int main() {
    // Read the dimensions of the grid
    int n = FastReader().nextInt();
    // Read the number of banned cells
    int m = FastReader().nextInt();

    // Initialize sets to keep track of banned rows and columns
    set<int> bannedRows, bannedCols;

    // Read each banned cell and add it to the appropriate set if it's not on the border
    for (int i = 0; i < m; i++) {
        int r = FastReader().nextInt();
        if (r > 1 && r < n) bannedRows.insert(r);
        int c = FastReader().nextInt();
        if (c > 1 && c < n) bannedCols.insert(c);
    }

    // Calculate the number of cells that can be reached, accounting for banned rows and columns
    int answer = (n - 2) * 2;
    answer -= bannedRows.size();
    answer -= bannedCols.size();

    // Adjust the answer if the grid size is odd and the center cell is not banned
    if (n % 2!= 0) {
        int mid = (n + 1) / 2;
        if (!bannedRows.count(mid) &&!bannedCols.count(mid)) {
            answer--;
        }
    }

    // Output the final answer
    cout << answer << endl;

    // Close the output stream
    return 0;
}

