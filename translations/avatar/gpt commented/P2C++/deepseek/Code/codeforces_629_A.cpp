#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> cake(n);
    int happiness = 0;
    int chocCount = 0;
    int nfat = 1;

    // Process each line of cake input
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        cake[i] = line;

        // Count the number of chocolates ('C') in the current line
        for (char j : line) {
            if (j == 'C') {
                chocCount++;
            }
        }

        // If there are more than one chocolate, calculate the happiness contribution
        if (chocCount > 1) {
            // Calculate the factorial of (chocCount - 1) and (chocCount - 2)
            for (int i = chocCount; i > chocCount - 2; --i) {
                nfat *= i;
            }
            // Update happiness based on the calculated factorial
            happiness += nfat / 2;
        }

        // Reset variables for the next line
        nfat = 1;
        chocCount = 0;
    }

    // Initialize a counter for vertical chocolate counting
    int posCount = 0;

    // Count chocolates in each column of the cake
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            // Count the number of chocolates ('C') in the current column
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }

        // If there are more than one chocolate in the column, calculate the happiness contribution
        if (chocCount > 1) {
            // Calculate the factorial of (chocCount - 1) and (chocCount - 2)
            for (int i = chocCount; i > chocCount - 2; --i) {
                nfat *= i;
            }
            // Update happiness based on the calculated factorial
            happiness += nfat / 2;
        }

        // Reset variables for the next column
        nfat = 1;
        chocCount = 0;
    }

    // Print the total happiness as an integer
    cout << happiness << endl;

    return 0;
}

