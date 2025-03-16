

#include <bits/stdc++.h> // Include the necessary header files

using namespace std ; // Using the'std' namespace

int main ( ) { // Starting point of the program
    int n, levels, sum = 0, sum2 = 0, sum3 = 0, level2, level3 ; // Declaring and initializing variables
    cin >> n >> levels ; // Reading the first two integer inputs 'n' and 'levels'
    int arr [ levels ] ; // Creating an integer array 'arr' of size 'levels'
    int count = 0 ; // Initializing the count variable to 0

    for ( int i = 0 ; i < levels ; i ++ ) { // Loop to read 'levels' number of integers and store them in 'arr'
        cin >> arr [ i ] ;
    }

    cin >> level2 ; // Reading the third integer input 'level2'
    level3 = levels + level2 ; // Calculating the size of 'arr2'
    int arr2 [ level3 ] ; // Creating an integer array 'arr2' of size 'level3'

    for ( int i = 0 ; i < levels ; i ++ ) { // Loop to copy elements of 'arr' to 'arr2'
        arr2 [ i ] = arr [ i ] ;
    }

    for ( int i = levels ; i < level3 ; i ++ ) { // Loop to read 'level2' number of integers and store them in 'arr2'
        cin >> arr2 [ i ] ;
    }

    int arr3 [ n ] ; // Creating an integer array 'arr3' of size 'n'
    int j = 0 ; // Initializing 'j' variable to 0

    for ( int i = 0 ; i < n ; i ++ ) { // Loop to initialize 'arr3' with numbers from 1 to 'n'
        arr3 [ i ] = ++ j ;
    }

    for ( int i = 0 ; i < n ; i ++ ) { // Outer loop to compare each element of 'arr3' with 'arr2'
        for ( int x = 0 ; x < level3 ; x ++ ) { // Inner loop to find a match between 'arr3[i]' and 'arr2[x]'
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

    return 0 ; // Returning 0 to indicate successful execution
}

