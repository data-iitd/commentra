#include <iostream> // Including necessary header for input/output
#include <vector>   // Including vector for dynamic array
#include <string>   // Including string for string manipulation

using namespace std;

int main() {
    string input; // Variable to store the first line of input
    getline(cin, input); // Reading the first line of input

    int n = input[0] - '0'; // Extracting the integer n from the input
    int m = input[1] - '0'; // Extracting the integer m from the input

    vector<string> ans(n); // Initializing a vector to store the resulting strings

    for (int i = 0; i < n; i++) { // Looping through each row
        string str; // Variable to store the current row
        getline(cin, str); // Reading the current row as a string
        string temp = ""; // String to build the resulting string for the current row

        for (int j = 0; j < m; j++) { // Looping through each character in the row
            if (str[j] == '-') { // Checking if the character is a '-'
                temp += "-"; // Appending '-' to the string
            } else {
                if ((i + j) % 2 == 1) { // Checking if the sum of indices is odd
                    temp += "W"; // Appending 'W' if the sum is odd
                } else {
                    temp += "B"; // Appending 'B' if the sum is even
                }
            }
        }
        ans[i] = temp; // Storing the resulting string in the ans vector
    }

    for (int i = 0; i < n; i++) { // Looping through each row again to print the results
        cout << ans[i] << endl; // Printing the resulting string for the current row
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
