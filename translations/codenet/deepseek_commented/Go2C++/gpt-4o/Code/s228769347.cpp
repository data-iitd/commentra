#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer from the input stream.
int getNextInt(istream &in) {
    int i;
    in >> i;
    return i;
}

// Main function handles file input/output based on command-line arguments.
// It reads integers from the specified file or standard input, sorts them,
// and calculates the number of valid triplets (i, j, m) where i < j < m and ll[m] < ll[i] + ll[j].
int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream inputFile;
    ofstream outputFile;
    istream *input = &cin;
    ostream *output = &cout;

    // Check if file paths are provided as command-line arguments.
    if (argc > 1) {
        inputFile.open(argv[1]);
        input = &inputFile;
        if (argc > 2) {
            outputFile.open(argv[2]);
            output = &outputFile;
        }
    }

    // Read the number of elements.
    int n = getNextInt(*input);
    vector<int> ll(n);

    // Read n integers into the vector ll.
    for (int i = 0; i < n; i++) {
        ll[i] = getNextInt(*input);
    }

    // Sort the vector ll.
    sort(ll.begin(), ll.end());

    // Initialize the answer variable.
    int ans = 0;

    // Iterate through possible triplets (i, j, m) where i < j < m.
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            // Add the number of valid m's to the answer.
            ans += l - (j + 1);
        }
    }

    // Print the final answer to the standard output.
    *output << ans << '\n';

    // Close files if they were opened.
    if (inputFile.is_open()) inputFile.close();
    if (outputFile.is_open()) outputFile.close();

    return 0;
}

// <END-OF-CODE>
