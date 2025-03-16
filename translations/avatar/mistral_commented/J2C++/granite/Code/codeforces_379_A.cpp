

#include <iostream> // Include the standard input/output stream objects

using namespace std ; // Use the standard namespace

int main ( ) { // Entry point of the program
    int a, b ; // Declare two integer variables 'a' and 'b'
    
    cin >> a >> b ; // Read the first and second integer values from the standard input stream
    
    int res = a ; // Initialize the result variable with the value of 'a'
    
    while ( a >= b ) { // Start a while loop that continues as long as 'a' is greater than or equal to 'b'
        res += ( a / b ) ; // Increment the result variable by the result of dividing 'a' by 'b'
        
        a = ( a / b ) + ( a % b ) ; // Update the value of 'a' with the result of the division and the remainder
    }
    
    cout << res ; // Print the value of the result variable to the standard output stream
    
    return 0 ; // Return a success status to the operating system
}

