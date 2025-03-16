

#include <bits/stdc++.h> // Include the necessary libraries for input/output and sorting arrays

using namespace std ; // Using the standard namespace for input/output and sorting arrays

int main ( ) {
    int n ; // Declare an integer variable n to store the number of elements in the array
    cin >> n ; // Read the number of elements in the array from the user input

    vector < int > a ( n ) ; // Create a vector of integers of size n to store the array elements

    // Read the array elements from the user input and store them in the vector
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> a [ i ] ;
    }

    sort ( a.begin ( ), a.end ( ) ) ; // Sort the vector in ascending order using the sort() function

    int min = a [ 0 ] ; // Assign the minimum value in the vector to the min variable

    // Check if all the elements in the vector are multiples of the minimum value
    for ( int value : a ) {
        if ( value % min!= 0 ) { // Check if the current element is not a multiple of the minimum value
            cout << - 1 << endl ; // Print -1 if any non-multiple of the minimum value is found
            return 0 ; // Exit the program if any non-multiple of the minimum value is found
        }
    }

    // Print the minimum value if all elements are multiples of the minimum value
    cout << min << endl ;

    return 0 ; // Return 0 to indicate successful execution of the program
}

