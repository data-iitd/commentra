// Including the required header file for the input output operations
#include <iostream>

// Including the required header file for the array operations
#include <array>

// Including the required header file for the math operations
#include <cmath>

// Defining the main function
int main ( ) {

    // Declaring the variable n to store the first integer input from the user
    int n ;

    // Declaring the variable m to store the second integer input from the user
    int m ;

    // Declaring the array arr to store the input integers
    std::array < int, 100000 > arr ;

    // Declaring the array gen to store the count of each integer occurrence
    std::array < int, 11 > gen ;

    // Reading the first integer input n from the user
    std::cin >> n ;

    // Reading the second integer input m from the user
    std::cin >> m ;

    // Reading the input integers and storing them in the arr array
    for ( int i = 0 ; i < n ; i ++ ) {
        std::cin >> arr [ i ] ;
        // Incrementing the count of the arr[i] in the gen array
        gen [ arr [ i ] ] ++ ;
    }

    // Calculating the answer
    long long ans = 0 ;
    for ( int i = 1 ; i <= m ; i ++ ) {
        for ( int k = 1 ; k <= m ; k ++ ) {
            // Skipping the case when i and k are equal to avoid double counting
            if ( i != k ) {
                // Multiplying the count of i and k and adding it to the answer
                ans += ( long long ) gen [ i ] * gen [ k ] ;
            }
        }
    }

    // Printing the answer divided by 2
    std::cout << ans / 2 << std::endl ;

    // Ending the main function
    return 0 ;
}

