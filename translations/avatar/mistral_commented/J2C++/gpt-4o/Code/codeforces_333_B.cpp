#include <iostream>  // Including necessary header for input and output
#include <vector>   // Including vector for dynamic array
#include <set>      // Including set for storing unique elements
#include <sstream>  // Including sstream for string stream
using namespace std; // Using standard namespace

class FastReader {
    // FastReader class declaration for fast input
    public:
        FastReader() {
            // Constructor declaration
            ios::sync_with_stdio(0); // Disable synchronization with C I/O
            cin.tie(0); // Untie cin from cout
        }

        string next() {
            // Method for reading the next token from the input
            string token;
            cin >> token; // Reading the next token
            return token; // Returning the token
        }

        int nextInt() {
            // Method for reading the next integer from the input
            return stoi(next()); // Converting the next token to an integer and returning it
        }

        long long nextLong() {
            // Method for reading the next long integer from the input
            return stoll(next()); // Converting the next token to a long integer and returning it
        }

        double nextDouble() {
            // Method for reading the next double from the input
            return stod(next()); // Converting the next token to a double and returning it
        }

        string nextLine() {
            // Method for reading the next line from the input
            string str;
            cin.ignore(); // Ignore the newline character
            getline(cin, str); // Reading the next line
            return str; // Returning the next line
        }
};

int main() {
    // Main method declaration
    FastReader in; // Creating an instance of FastReader class for reading input

    int n = in.nextInt(); // Reading the number of rows in the grid
    int m = in.nextInt(); // Reading the number of banned cells

    set<int> bannedRows; // Creating a set to store banned rows
    set<int> bannedCols; // Creating a set to store banned columns

    for (int i = 0; i < m; i++) {
        // Reading banned cells and adding them to the respective sets
        int r = in.nextInt();
        if (r > 1 && r < n) bannedRows.insert(r); // Adding banned row if it's valid

        int c = in.nextInt();
        if (c > 1 && c < n) bannedCols.insert(c); // Adding banned column if it's valid
    }

    int answer = (n - 2) * 2; // Initializing answer as the total number of cells in the grid minus the banned cells
    answer -= bannedRows.size(); // Subtracting the number of banned rows
    answer -= bannedCols.size(); // Subtracting the number of banned columns

    if (n % 2 != 0) {
        // Special case when the number of rows is odd
        int mid = (n + 1) / 2;
        if (bannedRows.find(mid) == bannedRows.end() && bannedCols.find(mid) == bannedCols.end()) {
            // If the middle cell is not banned, decrement the answer
            answer--;
        }
    }

    cout << answer << endl; // Writing the answer to the output stream
    return 0; // Returning from main
}

// <END-OF-CODE>
