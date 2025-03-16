#include <iostream>
#include <cmath>

using namespace std ;  // Using the standard namespace

const int MAX = 100 ;  // Defining a constant MAX with value 100

int check ( int n , int x [ ] , int y [ ] , int h [ ] , int cx , int cy ) {  // Method to check the height of water at position (cx, cy)
    int ch = - 1 ;  // Initializing the height to -1

    for ( int i = 0 ; i < n ; i ++ ) {  // Loop to iterate through all elements in the arrays x, y, and h
        if ( h[i] > 0 ) {  // If the height of the current element is greater than 0
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i] ;  // Calculate the distance and height of the current element and update the height if it's closer
            break ;  // Exit the loop once the closest element is found
        }
    }

    for ( int i = 0 ; i < n ; i ++ ) {  // Loop to check if all elements have the same height as the closest one
        if ( h[i] != max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0) ) {  // If the height is different, return -1 to indicate an error
            return -1 ;
        }
    }

    return ch ;  // Return the height of the water at position (cx, cy)
}

int main ( ) {  // Main method to start the program
    int n ;  // Declaring a variable to store the number of elements
    cin >> n ;  // Reading the number of elements n from the standard input

    int x [ n ] , y [ n ] , h [ n ] ;  // Creating arrays x, y, and h of size n

    for ( int i = 0 ; i < n ; i ++ ) {  // Loop to read and initialize the arrays
        cin >> x[i] >> y[i] >> h[i] ;
    }

    for ( int i = 0 ; i <= MAX ; i ++ ) {  // Outer loop to iterate through all possible positions (i, j)
        for ( int j = 0 ; j <= MAX ; j ++ ) {  // Inner loop to check all possible positions (i, j)
            int ch = check(n, x, y, h, i, j) ;  // Calling the check method to calculate the height of the water at position (i, j)
            if ( ch > 0 ) {  // If the height is greater than 0, print the position and height
                cout << i << " " << j << " " << ch << endl ;
            }
        }
    }

    return 0 ;  // Return 0 to indicate successful execution
}

