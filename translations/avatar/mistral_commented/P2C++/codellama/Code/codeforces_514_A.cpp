#include <iostream>
using namespace std;

int main () {

    // Declare a string variable `ip` to store the input string
    string ip;

    // Declare a string variable `st` to store the output string
    string st = "";

    // Take an input string `ip` from the user
    cin >> ip;

    // Check if the length of the input string is not equal to 1
    if ( ip.length () != 1 ) {

        // Check if the first character of the input string is equal to "9"
        if ( ip [ 0 ] == '9' ) {
            // Assign "9" to the variable `st`
            st = "9";
            // Slice the input string to exclude the first character
            ip = ip.substr ( 1 );
        }

        // Iterate through each character in the input string `ip`
        for ( int i = 0; i < ip.length (); i++ ) {

            // If the character is an integer greater than 4
            if ( ip [ i ] > '4' ) {
                // Calculate the difference between 9 and the integer
                int n = 9 - ip [ i ];
                // Add the difference to the string `st`
                st += to_string ( n );
            }

            // If the character is an integer less than or equal to 4
            else {
                // Add the character directly to the string `st`
                st += ip [ i ];
            }
        }
    }

    // If the length of the input string is equal to 1
    else {

        // Assign the input string to the variable `st`
        st = ip;
    }

    // Print the integer value of the string `st` to the console
    cout << stoi ( st ) << endl;

    return 0;
}

