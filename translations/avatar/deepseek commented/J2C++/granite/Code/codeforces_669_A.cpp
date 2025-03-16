

#include <iostream> // Importingiostream for input/output operations
#include <string> // Importing string for string manipulation

using namespace std; // Using the standard namespace

int main ( ) {
    int n ; // Declaring an integer variable n
    cin >> n ; // Reading an integer input from the user and storing it in variable n
    solve ( n ) ; // Calling the solve method with the input value n
    return 0 ; // Returning 0 to indicate successful execution of the program
}

void solve ( int n ) {
    // Calculating the result based on the given logic
    cout << ( ( n / 3 ) * 2 + ( n % 3 == 0? 0 : 1 ) ) << endl ; // Printing the result to the console
}

