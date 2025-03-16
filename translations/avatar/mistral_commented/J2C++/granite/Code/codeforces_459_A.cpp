

#include <bits/stdc++.h> // Include the standard library

using namespace std ; // Use the standard namespace

int main ( ) { // Define the main function
    int x1, y1, x2, y2 ; // Declare variables to store the coordinates
    cin >> x1 >> y1 >> x2 >> y2 ; // Read the input coordinates from the standard input stream
    if ( x1 == x2 ) { // Check if x1 and x2 are equal
        int dif = abs ( y1 - y2 ) ; // Calculate the absolute difference between y1 and y2
        cout << ( x1 + dif ) << " " << y1 << " " << ( x1 + dif ) << " " << y2 << endl ; // Print the result to the standard output stream
    } else if ( y1 == y2 ) { // Check if y1 and y2 are equal
        int dif = abs ( x1 - x2 ) ; // Calculate the absolute difference between x1 and x2
        cout << ( x1 ) << " " << ( y1 + dif ) << " " << ( x2 ) << " " << ( y2 + dif ) << endl ; // Print the result to the standard output stream
    } else if ( abs ( x1 - x2 ) == abs ( y1 - y2 ) ) { // Check if the absolute differences between x1 and x2 and y1 and y2 are equal
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl ; // Print the result to the standard output stream
    } else { // If none of the above conditions are met
        cout << - 1 << endl ; // Print -1 to the standard output stream
    }
    return 0 ; // Return 0 to indicate successful program execution
}

