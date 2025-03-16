
#include <bits/stdc++.h>

using namespace std;

int main ( ) {
    // Function to iterate over tokens in the input
    auto iterate_tokens = [ & ] ( ) {
        for ( string line ; getline ( cin, line ) ; ) {
            istringstream iss ( line ) ;
            for ( string word ; iss >> word ; ) {
                yield word ;
            }
        }
    } ;
    
    // Get the tokens from the input
    auto tokens = iterate_tokens ( ) ;
    
    // Read the number of points N
    int N = stoi ( next ( tokens ) ) ;
    
    // Initialize lists for x and y coordinates
    vector < int > x ( N ), y ( N ) ;
    
    // Read the x and y coordinates for each point
    for ( int i = 0 ; i < N ; i ++ ) {
        x [ i ] = stoi ( next ( tokens ) ) ;
        y [ i ] = stoi ( next ( tokens ) ) ;
    }
    
    // Call the solve function with the input values
    solve ( N, x, y ) ;
}

// 