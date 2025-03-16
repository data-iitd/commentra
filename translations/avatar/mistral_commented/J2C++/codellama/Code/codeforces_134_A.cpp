
#include <iostream>
#include <cstring>

using namespace std ;

int main ( ) {
    int n ; // Declaring the number of elements in the array
    int sum = 0 ; // Declaring the sum variable to 0
    int arr [ ] ; // Declaring the array

    cin >> n ; // Reading the number of elements in the array from the standard input
    arr = new int [ n ] ; // Creating an integer array of size n

    for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop to read and store the elements in the array
        cin >> arr [ i ] ; // Reading an integer value from the standard input and storing it in the current index of the array
        sum += arr [ i ] ; // Adding the current element to the sum variable
    }

    int c = 0 ; // Declaring the counter variable to 0
    string sb = "" ; // Declaring an empty string to store the indices of the elements that satisfy the condition

    for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop to check if an element satisfies the condition
        if ( ( sum - arr [ i ] ) % ( n - 1 ) == 0 && ( sum - arr [ i ] ) / ( n - 1 ) == arr [ i ] ) { // Checking if the current element satisfies the condition
            c ++ ; // Incrementing the counter variable if the condition is true
            sb += to_string ( i + 1 ) + " " ; // Appending the index of the current element to the string
        }
    }

    cout << c << endl ; // Printing the number of elements that satisfy the condition
    cout << sb << endl ; // Printing the indices of the elements that satisfy the condition separated by a space

    return 0 ; // Returning 0 to indicate that the program executed successfully
}

