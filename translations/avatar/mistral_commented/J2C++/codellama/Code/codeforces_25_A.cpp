#include <iostream>
using namespace std ;

int main ( ) {
    int n ;  // Declaring variables for the number of elements in the array and the array itself
    int array [ ] ;

    // Reading the number of elements in the array from user input
    cin >> n ;

    // Creating an array of size n+1 to store the input elements
    array = new int [ n + 1 ] ;

    // Reading the elements of the array from user input
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> array [ i ] ;  // Reading the i-th element of the array
    }

    int odd = 0 , even = 0 , odd_ind = 0 , even_ind = 0 ;  // Initializing variables for counting odd and even elements and their indices

    // Counting the number of odd and even elements and storing their indices
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( array [ i ] % 2 == 0 ) {  // If the current element is even
            even ++ ;  // Increment the count of even elements
            even_ind = i ;  // Store the index of the current even element
        } else {  // If the current element is odd
            odd ++ ;  // Increment the count of odd elements
            odd_ind = i ;  // Store the index of the current odd element
        }
    }

    // Determining the output based on the count of odd and even elements
    if ( odd > even ) {  // If there are more odd elements than even elements
        cout << even_ind << endl ;  // Print the index of the last even element
    } else {  // If there are more even elements than odd elements
        cout << odd_ind << endl ;  // Print the index of the last odd element
    }

    return 0 ;
}

