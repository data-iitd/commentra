

#include <iostream> // Including the necessary header files for using std::cin and std::cout.
#include <string> // Including the necessary header file for using std::string.

int main ( ) { // Starting the main method.
    std::string s ; // Initializing an empty string variable s to store the binary representation of the number n.
    int n ; // Initializing an integer variable n to store the user input.
    std::cin >> n ; // Reading the first integer input n from the user using the cin object of the std namespace.

    while ( n > 0 ) { // Starting a while loop that continues as long as n is greater than zero.
        int x = n % 2 ; // Calculating the last bit of the binary representation of n by finding the remainder of n divided by 2.
        n /= 2 ; // Updating the value of n by dividing it by 2 to get the next bit of the binary representation.
        s += std::to_string ( x ) ; // Appending the calculated bit to the string s.
    }

    int ans = 0 ; // Initializing an integer variable ans to 0 to store the number of 1's in the binary representation of n.

    for ( int i = 0 ; i < s.length ( ) ; i ++ ) { // Starting a for loop that iterates through each character in the string s.
        if ( s [ i ] == '1' ) { // Checking if the current character is '1'.
            ans ++ ; // If the character is '1', incrementing the value of ans by 1.
        }
    }

    std::cout << ans << std::endl ; // Printing the value of ans to the standard output stream using the cout object of the std namespace.

    return 0 ; // Returning 0 to indicate successful execution of the program.
}

