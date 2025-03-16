
#include <bits/stdc++.h> // Include necessary libraries for input/output operations and utility classes

using namespace std ; // Using the standard namespace

int main ( ) { // Main function definition
    ios_base::sync_with_stdio ( false ) ; // Disabling synchronization between C and C++ streams
    cin.tie ( NULL ) ; // Setting the tie of cin to NULL
    freopen ( "input.txt", "r", stdin ) ; // Redirecting standard input to the input.txt file
    freopen ( "output.txt", "w", stdout ) ; // Redirecting standard output to the output.txt file
    int n, k ; // Declaring variables n and k to store the length of the string and a parameter for some operation
    cin >> n >> k ; // Reading the first line of input and storing the values in n and k
    vector < int > cards ( 26, 0 ) ; // Initializing a vector of 26 integers to store the count of each character
    string s ; // Declaring a string variable s to store the input string
    cin >> s ; // Reading the string from the input
    for ( int t = 0 ; t < n ; t ++ ) { // Looping through the string to count occurrences
        cards [ s [ t ] - 'A' ] ++ ; // Incrementing the count of the corresponding character
    }
    long long ans = 0 ; // Initializing the answer variable to zero
    for ( int i = 0 ; i < k ; i ++ ) { // Looping k times to calculate the answer
        sort ( cards.begin ( ), cards.end ( ) ) ; // Sorting the cards vector
        long long change = min ( cards [ 25 ], k - i ) ; // Calculating the minimum between the largest count and the remaining k - i
        ans += change * change ; // Adding the square of the calculated value to ans
        cards [ 25 ] -= change ; // Decrementing the count of the largest character
        i += change - 1 ; // Adjusting the loop counter
    }
    cout << ans << endl ; // Printing the result
    return 0 ; // Returning 0 to indicate successful execution
}

