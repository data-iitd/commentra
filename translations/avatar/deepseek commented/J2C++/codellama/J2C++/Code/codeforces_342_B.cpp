
#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <map> 

using namespace std ; 

int main ( ) { 
    // Create a string to read input from the standard input
    string input ; 
    
    // Read the input and split it into an array of strings
    getline ( cin , input ) ; 
    istringstream iss ( input ) ; 
    vector < string > input_array ; 
    string token ; 
    while ( iss >> token ) { 
        input_array.push_back ( token ) ; 
    } 
    
    // Parse the required integers from the input
    int m = stoi ( input_array [ 1 ] ) ; 
    int s = stoi ( input_array [ 2 ] ) ; 
    int f = stoi ( input_array [ 3 ] ) ; 
    
    // Initialize the maximum time and a map to store the intervals
    int maxT = - 1 ; 
    map < int , vector < int > > map ; 
    
    // Read the intervals from the input and store them in the map
    while ( m > 0 ) { 
        getline ( cin , input ) ; 
        istringstream iss ( input ) ; 
        vector < string > mth ; 
        string token ; 
        while ( iss >> token ) { 
            mth.push_back ( token ) ; 
        } 
        int k = stoi ( mth [ 0 ] ) ; 
        map [ k ] = vector < int > ( ) ; 
        map [ k ].push_back ( stoi ( mth [ 1 ] ) ) ; 
        map [ k ].push_back ( stoi ( mth [ 2 ] ) ) ; 
        maxT = max ( maxT , k ) ; 
        m -- ; 
    } 
    
    // Initialize a string to build the sequence of actions
    string actions = "" ; 
    
    // Determine the direction of movement and initialize the current position
    char M = ( s < f ) ? 'R' : 'L' ; 
    int d = ( s < f ) ? + 1 : - 1 ; 
    int cur = s ; 
    
    // Variables to store the current interval's start and end
    int a = - 1 ; 
    int b = - 1 ; 
    
    // Build the sequence of actions based on the intervals and the current position
    for ( int t = 1 ; t <= maxT ; t ++ ) { 
        if ( map.find ( t ) != map.end ( ) ) { 
            a = map [ t ] [ 0 ] ; 
            b = map [ t ] [ 1 ] ; 
        } 
        if ( map.find ( t ) != map.end ( ) && ( ( cur >= a && cur <= b ) || ( cur + d >= a && cur + d <= b ) ) ) { 
            actions += 'X' ; 
        } else { 
            actions += M ; 
            cur += d ; 
        } 
        if ( cur == f ) break ; 
    } 
    
    // Continue moving in the determined direction until reaching the final position
    while ( cur != f ) { 
        actions += M ; 
        cur += d ; 
    } 
    
    // Print the sequence of actions
    cout << actions << endl ; 
    
    return 0 ; 
}

