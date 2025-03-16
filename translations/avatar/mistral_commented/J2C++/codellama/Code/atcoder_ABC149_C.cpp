// Including necessary libraries
#include <iostream>
#include <cmath>

// Defining the main function that takes no arguments
int main ( ) {
    // Declaring an integer variable 'x' to store the input
    int x ;

    // Reading an integer input from the user
    std::cin >> x ;

    // Checking if the number is even and not equal to 2
    if ( x != 2 && x % 2 == 0 )
        x ++ ;  // Incrementing the number if it's even and not 2

    // Starting an infinite loop
    while ( true ) {
        int i ;  // Declaring an integer variable 'i'
        double sqrtNum = sqrt ( x ) ; // Calculating the square root of the number 'x'

        // Checking for prime numbers using trial division method
        for ( i = 3 ; i <= sqrtNum ; i += 2 ) {
            if ( x % i == 0 ) // Checking if the number 'x' is divisible by 'i'
                break ; // If it's divisible, then 'i' is a factor and the loop is broken
        }

        // If 'i' is greater than the square root, then the number 'x' is prime
        if ( i > sqrtNum )
            break ; // Exiting the loop

        // If the loop didn't break, then the number 'x' is not prime, so we need to find the next prime number
        x += 2 ; // Incrementing the number by 2 to check the next odd number
    }

    // Printing the prime number found
    std::cout << x << std::endl ;

    // Ending the code
    return 0 ;
}

