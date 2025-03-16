

#include <iostream> // Including the standard input/output stream objects
#include <vector> // Including the vector container

using namespace std ; // Using the standard namespace

int main ( ) { // Main function to start the program
    int n ; // Declaring an integer variable 'n' to store the number of elements in the arrays
    cin >> n ; // Reading the number of elements in the arrays from the console
    vector < int > a ( n ) ; // Creating a vector 'a' of size 'n' to store the elements of the first array
    vector < int > b ( n, 0 ) ; // Creating a vector 'b' of size 'n' and initializing all elements to zero
    int s = - 1 ; // Initializing the variable's' to -1
    for ( int i = 0 ; i < n ; i ++ ) { // Loop to read and initialize the vectors 'a' and 'b'
        cin >> a [ i ] ; // Reading an integer value and storing it in the 'i'th position of vector 'a'
    }
    int tem = 1 ; // Initializing the variable 'tem' to 1
    int q = 0 ; // Initializing the variable 'q' to 0
    while ( q!= n ) { // Main loop to find the sequence length
        s ++ ; // Incrementing the variable's'
        if ( tem == 1 ) { // If 'tem' is 1, perform the first half of the loop
            for ( int i = 0 ; i < n ; i ++ ) {
                if ( a [ i ] <= q && b [ i ] == 0 ) { // Check if the current element in vector 'a' is less than or equal to 'q' and its corresponding element in vector 'b' is 0
                    b [ i ] = 1 ; // If so, set the corresponding element in vector 'b' to 1 and increment 'q'
                }
            }
            tem = 0 ; // Switching the value of 'tem' to 0
        } else { // If 'tem' is 0, perform the second half of the loop
            for ( int i = n - 1 ; i >= 0 ; i -- ) {
                if ( a [ i ] <= q && b [ i ] == 0 ) { // Check if the current element in vector 'a' is less than or equal to 'q' and its corresponding element in vector 'b' is 0
                    b [ i ] = 1 ; // If so, set the corresponding element in vector 'b' to 1 and increment 'q'
                }
            }
            tem = 1 ; // Switching the value of 'tem' to 1
        }
    }
    cout << s << endl ; // Printing the length of the sequence found
    return 0 ; // Returning 0 to indicate successful program execution
}

