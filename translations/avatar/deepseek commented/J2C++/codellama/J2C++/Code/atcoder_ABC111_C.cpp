
#include <iostream>
#include <algorithm>

using namespace std ; 

int main ( ) { 
    int n ; 
    cin >> n ; // Read the size of the array
    int v [ 100010 ] ; // Initialize the array to store the values
    for ( int i = 0 ; i < n ; i ++ ) { 
        cin >> v [ i ] ; // Read the values into the array
    } 
    int vo [ 100010 ] ; // Initialize arrays to count odd and even numbers
    int ve [ 100010 ] ; 
    int vt [ 100010 ] ; 
    fill ( vo , vo + 100010 , 0 ) ; // Initialize the count arrays to zero
    fill ( ve , ve + 100010 , 0 ) ; 
    fill ( vt , vt + 100010 , 0 ) ; 
    for ( int i = 0 ; i < n ; i ++ ) { 
        vt [ v [ i ] ] ++ ; // Count all numbers
        if ( i % 2 == 0 ) { 
            ve [ v [ i ] ] ++ ; // Count even numbers
        } else { 
            vo [ v [ i ] ] ++ ; // Count odd numbers
        } 
    } 
    sort ( vo , vo + 100010 , greater < int > ( ) ) ; // Sort the count arrays in descending order
    sort ( ve , ve + 100010 , greater < int > ( ) ) ; 
    sort ( vt , vt + 100010 , greater < int > ( ) ) ; 
    int ans = 0 ; 
    if ( vo [ 0 ] + ve [ 0 ] == vt [ 0 ] ) { // Check if the maximum counts are consecutive
        ans = min ( n - vo [ 0 ] - ve [ 1 ] , n - vo [ 1 ] - ve [ 0 ] ) ; // Calculate the minimum difference
    } else { 
        ans = n - vo [ 0 ] - ve [ 0 ] ; // Calculate the difference if not consecutive
    } 
    cout << ans << endl ; // Print the result
    return 0 ; // Return zero
}

