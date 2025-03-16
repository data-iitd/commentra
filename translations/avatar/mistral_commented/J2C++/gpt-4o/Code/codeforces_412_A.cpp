#include <iostream>  // Including the iostream library for input and output
#include <string>    // Including the string library for string manipulation

using namespace std; // Using the standard namespace

int main() { // Main function to start the program
    int n, k; // Declare integers n and k
    cin >> n >> k; // Read the first two integer inputs from the user
    string a; // Declare a string variable
    cin >> a; // Read the string input from the user

    if (k > n / 2) { // Check if k is greater than n/2
        while (k < n) { // If true, print "RIGHT" until k equals n
            cout << "RIGHT" << endl;
            k++;
        }
    } else { // Else if k is less than or equal to n/2
        while (k > 1) { // Print "LEFT" until k equals 1
            cout << "LEFT" << endl;
            k--;
        }
    }

    if (k == 1) { // If k equals 1
        for (int i = 0; i < a.length(); i++) { // Iterate through each character in the string
            cout << "PRINT " << a[i] << endl; // Print the character
            if ((i + 1) < a.length()) { // If the index is not the last one
                cout << "RIGHT" << endl; // Print "RIGHT"
            }
        }
    } else { // Else if k is not equal to 1
        for (int i = a.length() - 1; i >= 0; i--) { // Iterate through each character in reverse order
            cout << "PRINT " << a[i] << endl; // Print the character
            if ((i - 1) >= 0) { // If the index is not the first one
                cout << "LEFT" << endl; // Print "LEFT"
            }
        }
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
