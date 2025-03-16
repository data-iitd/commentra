#include <iostream>
#include <string>
#include <algorithm>
using namespace std ; // Using the standard namespace

struct c462b { // Struct definition for c462b
    int left = 0 ; // Property to store the count
    bool operator < ( const c462b & o ) const { // Method to compare based on the left property
        return left < o.left ; // Returning the difference in left properties
    }
} ;

int main ( ) { // Main function definition
    int n , k ; // Declaring variables to store the length and parameter
    cin >> n >> k ; // Reading the length and parameter
    c462b cards [ 26 ] ; // Initializing an array of c462b objects with 26 elements
    for ( int i = 0 ; i < 26 ; i ++ ) { // Looping through the array to initialize each element
        cards [ i ].left = 0 ; // Initializing each c462b object
    }
    string s ; // Declaring a string to store the input
    cin >> s ; // Reading the string from the input
    for ( int t = 0 ; t < n ; t ++ ) { // Looping through the string to count occurrences
        cards [ s [ t ] - 'A' ].left ++ ; // Incrementing the left property of the corresponding c462b object
    }
    long ans = 0 ; // Initializing the answer variable to zero
    for ( int i = 0 ; i < k ; i ++ ) { // Looping k times to calculate the answer
        sort ( cards , cards + 26 ) ; // Sorting the cards array
        long change = min ( cards [ 25 ].left , k - i ) ; // Calculating the minimum between the largest left value and the remaining k - i
        ans += change * change ; // Adding the square of the calculated value to ans
        cards [ 25 ].left -= change ; // Decrementing the left property of the largest element
        i += change - 1 ; // Adjusting the loop counter
    }
    cout << ans << endl ; // Printing the result
    return 0 ; // Returning zero
}

