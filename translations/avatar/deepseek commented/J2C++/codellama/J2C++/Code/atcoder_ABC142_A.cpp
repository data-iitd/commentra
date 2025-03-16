
#include <iostream>
#include <cmath>
#include <iomanip>

// Including necessary header files for input/output operations and mathematical calculations

using namespace std ;

// Declaring namespace std to avoid using std:: before every function call

int main ( ) {
    double input ;
    
    // Declaring a double variable to store the input
    
    cin >> input ;
    
    // Reading a double value from the input
    
    double countOdd = round ( input / 2 ) ;
    
    // Calculating the number of odd numbers up to the given input
    
    cout << fixed << setprecision ( 10 ) << countOdd / input << endl ;
    
    // Using setprecision to set the precision to 10 and printing the result
    
    return 0 ;
    
    // Returning 0 to indicate successful execution
    
}

