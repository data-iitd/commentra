

#include <bits/stdc++.h> // Include the standard library header file

using namespace std ; // Using the standard namespace

int main ( ) { // Starting point of the program
    int n ; // Declaring an integer variable n to store the number of elements in the array
    cin >> n ; // Reading the number of elements in the array from the standard input
    int a [ n ] ; // Creating an integer array of size n
    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the array to read its elements from the standard input
        cin >> a [ i ] ;
    }
    string s ; // Declaring a string variable s to store the input string
    cin >> s ; // Reading the string from the standard input
    long long sum = 0 ; // Initializing the sum variable to zero
    for ( int i = 0 ; i < s.length ( ) ; i ++ ) { // Iterating through the string to calculate the sum of the array elements corresponding to the 'B' characters
        if ( s [ i ] == 'B' ) sum += a [ i ] ;
    }
    long long ans = sum ; // Initializing the answer variable with the sum calculated above
    long long sum1 = sum ; // Initializing a temporary sum variable with the sum calculated above
    for ( int i = 0 ; i < s.length ( ) ; i ++ ) { // Iterating through the string to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
        if ( s [ i ] == 'A' ) sum1 += a [ i ] ;
        else sum1 -= a [ i ] ;
        ans = max ( ans, sum1 ) ;
    }
    sum1 = sum ; // Resetting the temporary sum variable with the sum calculated at the beginning
    for ( int i = s.length ( ) - 1 ; i >= 0 ; i -- ) { // Iterating through the string in reverse order to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
        if ( s [ i ] == 'A' ) sum1 += a [ i ] ;
        else sum1 -= a [ i ] ;
        ans = max ( ans, sum1 ) ;
    }
    cout << ans << endl ; // Printing the maximum sum found
    return 0 ; // Returning 0 to indicate successful execution of the program
}

