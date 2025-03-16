
#include <iostream> // Importing the necessary classes for input/output operations
#include <string> // Importing the necessary class for strings

using namespace std;

int main() { // Main method to execute the program
    string line; // Variable to store the first line of input
    getline(cin, line); // Reading the first line and storing it in the line variable
    int n = line[0] - '0'; // Extracting the integer n from the first character of the line
    int m = line[1] - '0'; // Extracting the integer m from the second character of the line

    string ans[n]; // Array to store the resulting strings

    for (int i = 0; i < n; i++) { // Looping through each row
        getline(cin, line); // Reading the current row as a string
        string temp = ""; // Variable to store the resulting string for the current row

        for (int j = 0; j < m; j++) { // Looping through each character in the row
            if (line[j] == '-') { // Checking if the character is a '-'
                temp += "-"; // Appending '-' to the resulting string
            } else {
                if ((i + j) % 2 == 1) { // Checking if the sum of indices is odd
                    temp += "W"; // Appending 'W' if the sum is odd
                } else {
                    temp += "B"; // Appending 'B' if the sum is even
                }
            }
        }
        ans[i] = temp; // Storing the resulting string for the current row in the ans array
    }

    for (int i = 0; i < n; i++) { // Looping through each row again to print the results
        cout << ans[i] << endl; // Printing the resulting string for the current row
    }

    return 0; // Returning 0 to indicate successful execution of the program
}

