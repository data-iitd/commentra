#include <iostream> // Including the necessary header files
#include <string>
#include <sstream>

using namespace std; // Using the standard namespace

int main() { // Main function to execute the program
    string inp; // Declaring a string to store the input
    getline(cin, inp); // Reading the first line and storing it in the string
    stringstream ss(inp); // Creating a stringstream to split the input string
    int n, m; // Declaring integers to store the values of n and m
    ss >> n >> m; // Extracting the values of n and m from the stringstream

    string ans[n]; // Declaring an array to store the resulting strings

    for (int i = 0; i < n; i++) { // Looping through each row
        getline(cin, inp); // Reading the current row as a string
        stringstream temp; // Creating a stringstream to build the resulting string for the current row

        for (int j = 0; j < m; j++) { // Looping through each character in the row
            if (inp[j] == '-') { // Checking if the character is a '-'
                temp << "-"; // Appending '-' to the stringstream
            } else {
                if ((i + j) % 2 == 1) { // Checking if the sum of indices is odd
                    temp << "W"; // Appending 'W' if the sum is odd
                } else {
                    temp << "B"; // Appending 'B' if the sum is even
                }
            }
        }
        ans[i] = temp.str(); // Converting the stringstream to a string and storing it in the ans array
    }

    for (int i = 0; i < n; i++) { // Looping through each row again to print the results
        cout << ans[i] << endl; // Printing the resulting string for the current row
    }
    return 0; // Returning 0 to indicate successful execution
}

