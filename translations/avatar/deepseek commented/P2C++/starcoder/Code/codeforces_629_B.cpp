
#include <bits/stdc++.h>

using namespace std;

// Define the maximum number of time slots
#define N 368

// Function to calculate the maximum number of people at any time slot
int max_people ( int m [ ], int f [ ] ) {
    // Initialize variables to store the maximum number of people and the current number of people
    int a = 0, b = 0, c = 0 ;
    
    // Calculate the cumulative sum of changes and find the maximum number of people at any time slot
    for ( int i = 0 ; i < N ; i ++ ) {
        a += m [ i ] ;
        b += f [ i ] ;
        if ( min ( a, b ) > c )
            c = min ( a, b ) ;
    }
    
    // Return the maximum number of people at any time slot
    return c ;
}

// Function to read the number of operations
int main ( ) {
    // Read the number of operations
    int n ;
    cin >> n ;
    
    // Initialize lists to store changes for males and females
    int m [ N ], f [ N ] ;
    
    // Read the number of operations
    for ( int i = 0 ; i < n ; i ++ ) {
        // Read each line, strip newline, and split into gender, start time, and end time
        string x, a, b ;
        cin >> x >> a >> b ;
        a = stoi ( a ) ;
        b = stoi ( b ) + 1 ;
        
        // Update the changes in the lists based on gender
        if ( x == "M" ) {
            m [ a ] += 2 ;
            m [ b ] -= 2 ;
        }
        else {
            f [ a ] += 2 ;
            f [ b ] -= 2 ;
        }
    }
    
    // Print the maximum number of people at any time slot
    cout << max_people ( m, f ) << endl ;
    
    // Return 0
    return 0 ;
}

