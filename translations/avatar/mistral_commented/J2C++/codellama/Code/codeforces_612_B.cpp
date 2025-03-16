// Including the iostream header for input and output
#include <iostream>

// Defining the main method as the entry point of the program
int main ( ) {
    // Declaring an integer variable n to store the number of test cases
    int n ;

    // Declaring an integer array dp of size 200001 to store the position of each number in the sequence
    int dp [ 200001 ] ;

    // Declaring a long variable ans to store the answer
    long ans = 0 ;

    // Reading the number of test cases
    std::cin >> n ;

    // Iterating through each test case
    for ( int i = 0 ; i < n ; i ++ ) {
        // Reading the next number to be added to the sequence
        int num ;
        std::cin >> num ;

        // Storing the position of the number in the dp array
        dp [ num ] = i ;
    }

    // Calculating the answer by iterating through the dp array and finding the absolute difference between the positions of consecutive numbers
    for ( int i = 2 ; i <= n ; i ++ ) {
        // Adding the absolute difference to the answer
        ans += abs ( dp [ i ] - dp [ i - 1 ] ) ;
    }

    // Printing the answer to the console
    std::cout << ans << std::endl ;

    // Ending the code
    return 0 ;
}

