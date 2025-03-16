
#include <bits/stdc++.h> // Importing the standard library

using namespace std ; // Using the standard library

int main ( ) { // Starting point of the program
    int n, levels, level2, level3, count = 0 ; // Declaring variables
    cin >> n >> levels ; // Reading the first two integers
    int arr [ levels ], arr2 [ level3 ], arr3 [ n ] ; // Creating integer arrays

    for ( int i = 0 ; i < levels ; i ++ ) { // Loop to read 'levels' number of integers and store them in 'arr'
        cin >> arr [ i ] ;
    }

    level2 = n - levels ; // Calculating the size of 'arr2'
    level3 = levels + level2 ; // Calculating the size of 'arr2'

    for ( int i = 0 ; i < arr.length ; i ++ ) { // Loop to copy elements of 'arr' to 'arr2'
        arr2 [ i ] = arr [ i ] ;
    }

    for ( int i = arr.length ; i < level3 ; i ++ ) { // Loop to read 'level2' number of integers and store them in 'arr2'
        cin >> arr2 [ i ] ;
    }

    for ( int i = 0 ; i < n ; i ++ ) { // Loop to initialize 'arr3' with numbers from 1 to 'n'
        arr3 [ i ] = i + 1 ;
    }

    for ( int i = 0 ; i < n ; i ++ ) { // Outer loop to compare each element of 'arr3' with 'arr2'
        for ( int x = 0 ; x < arr2.length ; x ++ ) { // Inner loop to find a match between 'arr3[i]' and 'arr2[x]'
            if ( arr3 [ i ] == arr2 [ x ] ) { // If a match is found
                count ++ ; // Increment the count variable
                break ; // Exit the inner loop
            }
        }
    }

    if ( count == n ) { // If all elements of 'arr3' are present in 'arr2'
        cout << "I become the guy." << endl ; // Print the message
    } else { // Otherwise
        cout << "Oh, my keyboard!" << endl ; // Print the error message
    }

    return 0 ; // Returning 0 to end the program
}

