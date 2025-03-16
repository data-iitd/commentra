
#include <iostream>
#include <algorithm>

using namespace std ;

int main ( ) {
    int n ; // Declaring a variable to store the number of elements in the array
    cin >> n ; // Reading the number of elements in the array from the user input
    int a [ n ] ; // Creating an integer array of size n

    // Initializing the array with user input
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> a [ i ] ; // Reading an integer value from the user input and storing it in the array at the current index
    }

    sort ( a , a + n ) ; // Sorting the array in ascending order using the sort() function

    int min = a [ 0 ] ; // Assigning the minimum value in the array to the min variable

    // Checking if all the elements in the array are multiples of the minimum value
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] % min != 0 ) { // Checking if the current element is not a multiple of the minimum value
            cout << - 1 << endl ; // Printing -1 if any non-multiple of the minimum value is found
            return 0 ; // Exiting the function if any non-multiple of the minimum value is found
        }
    }

    // Printing the minimum value if all elements are multiples of the minimum value
    cout << min << endl ;

    return 0 ;
}

