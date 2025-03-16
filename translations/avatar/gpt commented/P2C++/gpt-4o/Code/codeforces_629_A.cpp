#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Read the number of lines (n) from user input
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input

    // Initialize a vector to store the cake representation and variables for happiness and chocolate count
    vector<string> cake;
    double happiness = 0;
    int chocCount = 0;
    int nfat = 1;

    // Process each line of cake input
    for (int i = 0; i < n; i++) {
        // Read a line of cake representation
        string line;
        getline(cin, line);
        // Append the line to the cake vector
        cake.push_back(line);
        
        // Count the number of chocolates ('C') in the current line
        for (char j : line) {
            if (j == 'C') {
                chocCount++;
            }
        }
        
        // If there are more than one chocolate, calculate the happiness contribution
        if (chocCount > 1) {
            // Calculate the factorial of (chocCount - 1) and (chocCount - 2)
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            // Update happiness based on the calculated factorial
            happiness += nfat / 2.0;
        }
        
        // Reset variables for the next line
        nfat = 1;
        chocCount = 0;
    }

    // Initialize a counter for vertical chocolate counting
    chocCount = 0;

    // Count chocolates in each column of the cake
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            // Count the number of chocolates ('C') in the current column
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        
        // If there are more than one chocolate in the column, calculate the happiness contribution
        if (chocCount > 1) {
            // Calculate the factorial of (chocCount - 1) and (chocCount - 2)
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            // Update happiness based on the calculated factorial
            happiness += nfat / 2.0;
        }
        
        // Reset variables for the next column
        nfat = 1;
        chocCount = 0;
    }

    // Print the total happiness as an integer
    cout << static_cast<int>(happiness) << endl;

    return 0;
}

// <END-OF-CODE>
