
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cstdlib>

using namespace std;

void solve ( int N , vector < int > x , vector < int > y ) {
    // Generate a list of indices from 0 to N-1
    vector < int > indices ( N );
    for ( int i = 0 ; i < N ; i++ ) {
        indices [ i ] = i;
    }
    
    // Generate all permutations of the indices
    vector < vector < int > > permutations;
    do {
        permutations.push_back ( indices );
    } while ( next_permutation ( indices.begin ( ) , indices.end ( ) ) );
    
    // Initialize a list to store the total distances for each permutation
    vector < double > distances;
    
    // Iterate over each permutation
    for ( int i = 0 ; i < permutations.size ( ) ; i++ ) {
        // Initialize the total distance for the current permutation
        double total_distance = 0;
        
        // Calculate the distance between consecutive points in the permutation
        for ( int j = 0 ; j < N - 1 ; j++ ) {
            int f = permutations [ i ] [ j ];
            int t = permutations [ i ] [ j + 1 ];
            double distance = sqrt ( ( x [ t ] - x [ f ] ) * ( x [ t ] - x [ f ] ) + ( y [ t ] - y [ f ] ) * ( y [ t ] - y [ f ] ) );
            total_distance += distance;
        }
        
        // Append the total distance of the current permutation to the distances list
        distances.push_back ( total_distance );
    }
    
    // Calculate the average distance by averaging all stored distances
    double result = accumulate ( distances.begin ( ) , distances.end ( ) , 0.0 ) / distances.size ( );
    
    // Print the result
    cout << result << endl;
    
    // Return from the function
    return;
}

int main ( ) {
    // Function to iterate over tokens in the input
    auto iterate_tokens = [ ] ( ) {
        string line;
        while ( getline ( cin , line ) ) {
            istringstream iss ( line );
            copy ( istream_iterator < string > ( iss ) , istream_iterator < string > ( ) , ostream_iterator < string > ( cout , " " ) );
            cout << endl;
        }
    };
    
    // Get the tokens from the input
    auto tokens = iterate_tokens ( );
    
    // Read the number of points N
    int N = stoi ( next ( tokens ) );
    
    // Initialize lists for x and y coordinates
    vector < int > x ( N );
    vector < int > y ( N );
    
    // Read the x and y coordinates for each point
    for ( int i = 0 ; i < N ; i++ ) {
        x [ i ] = stoi ( next ( tokens ) );
        y [ i ] = stoi ( next ( tokens ) );
    }
    
    // Call the solve function with the input values
    solve ( N , x , y );
    
    // Return from the function
    return 0;
}

