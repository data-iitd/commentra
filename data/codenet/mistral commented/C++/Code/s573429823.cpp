#include <iostream> // Include the standard input/output library
using namespace std; // Use the standard input/output namespace

int main(void) // Define the main function, entry point of the program
{
    // Declare variables
    unsigned long n; // Declare an unsigned long integer variable to store the input number
    bool flg = false; // Declare a boolean variable (flag) and initialize it to false

    // Read the input number
    cin >> n;

    // Check if n is less than 4
    if( n<4 ) {
        cout << "No" << endl; // Print "No" and exit the program
        return 0;
    }

    // Check if n can be represented as a sum of two integers, each a multiple of 4 and 7
    for( int i=0; i<=(n/4); i++ ) { // Outer loop: i from 0 to n/4
        for( int j=0; j<=(n/7); j++ ) { // Inner loop: j from 0 to n/7
            if( (i*4+j*7)==n ) { // Check if the sum of i*4 and j*7 equals n
                flg = true; // Set the flag to true if found
                break; // Exit both loops
            }
        }
        if(flg) break; // Exit the outer loop if flag is true
    }

    // Print the result
    if(flg) {
        cout << "Yes" << endl; // Print "Yes" if n can be represented as a sum of two integers, each a multiple of 4 and 7
    } else {
        cout << "No" << endl; // Print "No" otherwise
    }

    return 0; // Exit the program
}
