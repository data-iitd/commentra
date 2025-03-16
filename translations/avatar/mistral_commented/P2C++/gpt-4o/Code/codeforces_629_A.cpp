#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;  // Read the number of lines in the input
    vector<string> cake;  // Initialize a vector to store each line
    double happiness = 0; // Initialize happiness variable to zero
    int chocCount = 0;    // Initialize chocolate count variable to zero
    int nfat = 1;         // Initialize nFAT variable to 1
    cin.ignore(); // To ignore the newline character after reading n

    for (int i = 0; i < n; i++) {  // Iterate through each line in the input
        string line;
        getline(cin, line);  // Read a line
        cake.push_back(line); // Append the line to the vector

        for (char j : line) { // Iterate through each character in the line
            if (j == 'C') {   // If the character is 'C', increment chocolate count
                chocCount++;
            }
        }

        if (chocCount > 1) {  // If there are more than one 'C' in the line
            nfat = 1;         // Reset nFAT to 1
            for (int k = chocCount; k > chocCount - 2; k--) {  // Calculate nFAT using the chocolate count
                nfat *= k;
            }
            happiness += nfat / 2;  // Add happiness based on the nFAT value
        }

        chocCount = 0;    // Reset chocolate count to zero
    }

    chocCount = 0; // Reset chocolate count for column calculation
    for (int j = 0; j < n; j++) {  // Iterate through each column in the cake
        for (int i = 0; i < n; i++) {  // Iterate through each line in the cake
            if (cake[i][j] == 'C') {  // If the character at the position (i,j) is 'C', increment chocolate count
                chocCount++;
            }
        }

        if (chocCount > 1) {  // If there are more than one 'C' in the column
            nfat = 1;         // Reset nFAT to 1
            for (int k = chocCount; k > chocCount - 2; k--) {  // Calculate nFAT using the chocolate count
                nfat *= k;
            }
            happiness += nfat / 2;  // Add happiness based on the nFAT value
        }

        chocCount = 0;    // Reset chocolate count to zero
    }

    cout << static_cast<int>(happiness) << endl;  // Print the final happiness value as an integer.

    return 0;
}  // <END-OF-CODE>
