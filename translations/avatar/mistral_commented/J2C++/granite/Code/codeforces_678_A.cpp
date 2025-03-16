

#include <iostream> // Include the necessary header file for input/output operations

int main ( ) { // Entry point of the program
    int n, k, z ; // Declare three integer variables `n`, `k`, and `z`
    std::cin >> n >> k ; // Read the first two integers `n` and `k` from the standard input
    n ++ ; // Increment the value of `n` by 1
    if ( n % k!= 0 ) { // Check if the remainder of `n` divided by `k` is equal to 0
        z = k - n % k ; // If the remainder is not equal to 0, calculate the difference between `k` and the remainder and assign it to `z`
    }
    std::cout << n + z << std::endl ; // Print the value of `n` plus the value of `z`
    return 0 ; // Return 0 to indicate successful execution of the program
}

