
#include <bits/stdc++.h> 
using namespace std ; 

int main ( ) { 
    // Step 1: Read the input value `n` which represents the number of elements to process.
    int n ; 
    cin >> n ; 
    
    // Step 2: Read the array of size `3 * n` from the standard input.
    vector < int > array ( 3 * n ) ; 
    for ( int i = 0 ; i < array.size ( ) ; i ++ ) 
        cin >> array [ i ] ; 
    
    // Step 3: Sort the array in ascending order.
    sort ( array.begin ( ), array.end ( ) ) ; 
    
    // Step 4: Initialize a variable `head` to point to the second last element of the array.
    int head = array.size ( ) - 2 ; 
    
    // Step 5: Initialize a variable `res` to store the result.
    long long res = 0 ; 
    
    // Step 6: Iterate `n` times, in each iteration:
    // - Add the value at the `head` position to `res`.
    // - Decrement `head` by 2.
    for ( int i = 0 ; i < n ; i ++ ) { 
        res += array [ head ] ; 
        head -= 2 ; 
    } 
    
    // Step 7: Print the result `res`.
    cout << res << endl ; 
    
    // 