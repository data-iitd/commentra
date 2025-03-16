
#include <bits/stdc++.h> // Importing the necessary classes for using std::cin, std::cout and std::vector from the C++ standard library.

using namespace std ;

int main ( ) { // Starting the main method.
    int n ;
    cin >> n ; // Reading the first integer input n from the user using the >> operator.

    string s = "" ; // Initializing an empty string variable s to store the binary representation of the number n.

    while ( n > 0 ) { // Starting a while loop that continues as long as n is greater than zero.
        int x = n % 2 ; // Calculating the last bit of the binary representation of n by finding the remainder of n divided by 2.
        n /= 2 ; // Updating the value of n by dividing it by 2 to get the next bit of the binary representation.
        s += to_string ( x ) ; // Appending the calculated bit to the string s using the to_string() function.
    }

    int ans = 0 ; // Initializing an integer variable ans to 0 to store the number of 1's in the binary representation of n.

    for ( int i = 0 ; i < s.length ( ) ; i ++ ) { // Starting a for loop that iterates through each character in the string s.
        if ( s.at ( i ) == '1' ) { // Checking if the current character is '1'.
            ans ++ ; // If the character is '1', incrementing the value of ans by 1.
        }
    }

    cout << ans << endl ; // Printing the value of ans to the standard output stream using the << operator.

    return 0 ;
}

