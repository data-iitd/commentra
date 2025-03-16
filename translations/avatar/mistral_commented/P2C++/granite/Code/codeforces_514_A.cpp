
#include <iostream>
#include <string>

using namespace std;

int main () {

    // Take an input string `ip` from the user
    string ip;
    cin >> ip;

    // Initialize an empty string `st`
    string st = "";

    // Check if the length of the input string is not equal to 1
    if ( ip.length ()!= 1 ) {

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
            if ( ip [ i ] - '0' > 4 ) {
                // Calculate the difference between 9 and the integer
                int n = 9 - ( ip [ i ] - '0' );
                // Convert the difference to a string and add it to the string `st`
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
    cout << stt << endl;

    return 0;
}

