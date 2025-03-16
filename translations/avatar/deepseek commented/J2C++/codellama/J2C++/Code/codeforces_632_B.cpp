
#include <iostream>
#include <string>
#include <cmath>

using namespace std ; 

int main ( ) { 
    // Step 1: Reading Input
    int n ; // Declare and initialize n to store the size of the array
    cin >> n ; 
    int a [ ] = new int [ n ] ; // Declare and initialize a to store the elements of the array
    for ( int i = 0 ; i < n ; i ++ ) { 
        cin >> a [ i ] ; // Read the elements of the array
    }
    
    // Step 2: Reading a String
    string s ; // Declare and initialize s to store the string
    cin >> s ; 
    
    // Step 3: Initial Sum Calculation
    long sum = 0 ; // Declare and initialize sum to store the sum of elements in array a where corresponding character in s is 'B'
    
    // Step 4: First Loop
    for ( int i = 0 ; i < s.length ( ) ; i ++ ) { 
        char ch = s.at ( i ) ; // Get the character at position i in the string s
        if ( ch == 'B' ) sum += a [ i ] ; // Add the element at position i in array a to sum if the character is 'B'
    }
    
    // Step 5: Main Logic
    long ans = sum ; // Declare and initialize ans with the initial sum
    long sum1 = sum ; // Declare and initialize sum1 for further calculations
    
    // First nested loop to calculate the maximum possible sum by flipping characters in s
    for ( int i = 0 ; i < s.length ( ) ; i ++ ) { 
        if ( s.at ( i ) == 'A' ) sum1 += a [ i ] ; // Add the element at position i in array a to sum1 if the character is 'A'
        else sum1 -= a [ i ] ; // Subtract the element at position i in array a from sum1 if the character is 'B'
        ans = max ( ans , sum1 ) ; // Update ans with the maximum value between ans and sum1
    }
    
    // Second nested loop to calculate the maximum possible sum by flipping characters in s from right to left
    sum1 = sum ; // Reset sum1 to the initial sum
    for ( int i = s.length ( ) - 1 ; i >= 0 ; i -- ) { 
        if ( s.at ( i ) == 'A' ) sum1 += a [ i ] ; // Add the element at position i in array a to sum1 if the character is 'A'
        else sum1 -= a [ i ] ; // Subtract the element at position i in array a from sum1 if the character is 'B'
        ans = max ( ans , sum1 ) ; // Update ans with the maximum value between ans and sum1
    }
    
    // Step 6: Output
    cout << ans << endl ; // Print the maximum sum found
    
    return 0 ; 
}

