
#include <iostream> // Including the standard input/output stream objects iostream and ostream
#include <vector> // Including the vector container from the standard template library

using namespace std ; // Using the standard namespace

int main ( ) { // Starting the main method
    int n ; // Declaring an integer variable n to store the number of elements in the array
    cin >> n ; // Reading the number of elements in the array from the standard input
    vector < int > arr ( n ) ; // Creating a vector of size n to store the elements of the array
    int sum = 0 ; // Initializing the sum variable to 0

    for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop to read and store the elements in the vector
        cin >> arr [ i ] ; // Reading an integer value from the standard input and storing it in the current index of the vector
        sum += arr [ i ] ; // Adding the current element to the sum variable
    }

    int c = 0 ; // Initializing the counter variable to 0
    stringstream sb ; // Creating an empty stringstream object to store the indices of the elements that satisfy the condition

    for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop to check if an element satisfies the condition
        if ( ( sum - arr [ i ] ) % ( n - 1 ) == 0 && ( sum - arr [ i ] ) / ( n - 1 ) == arr [ i ] ) { // Checking if the current element satisfies the condition
            c ++ ; // Incrementing the counter variable if the condition is true
            sb << ( i + 1 ) << " " ; // Appending the index of the current element to the stringstream object
        }
    }

    cout << c << endl ; // Printing the number of elements that satisfy the condition
    cout << sb.str ( ) ; // Printing the indices of the elements that satisfy the condition separated by a space

    return 0 ; // Returning 0 to indicate successful execution of the program
}

