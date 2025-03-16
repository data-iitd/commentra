

#include <bits/stdc++.h>
using namespace std;

void solve ( int N, vector < int > & x, vector < int > & y ) {
    // Generate a list of indices from 0 to N-1
    vector < int > indices ( N );
    for ( int i = 0 ; i < N ; i ++ ) {
        indices [ i ] = i;
    }
    
    // Generate all permutations of the indices
    vector < vector < int > > permutations;
    do {
        permutations.push_back ( indices );
    } while ( next_permutation ( indices.begin ( ), indices.end ( ) ) );
    
    // Initialize a list to store the total distances for each permutation
    vector < double > distances;
    
    // Iterate over each permutation
    for ( auto permutation : permutations ) {
        // Initialize the total distance for the current permutation
        double total_distance = 0;
        
        // Calculate the distance between consecutive points in the permutation
        for ( int i = 0 ; i < N - 1 ; i ++ ) {
            int f = permutation [ i ];
            int t = permutation [ i + 1 ];
            double distance = sqrt ( pow ( x [ t ] - x [ f ], 2 ) + pow ( y [ t ] - y [ f ], 2 ) );
            total_distance += distance;
        }
        
        // Append the total distance of the current permutation to the distances list
        distances.push_back ( total_distance );
    }
    
    // Calculate the average distance by averaging all stored distances
    double result = accumulate ( distances.begin ( ), distances.end ( ), 0.0 ) / distances.size ( );
    
    // Print the result
    cout << result << endl;
}

int main ( ) {
    // Read the number of points N
    int N;
    cin >> N;
    
    // Initialize lists for x and y coordinates
    vector < int > x ( N );
    vector < int > y ( N );
    
    // Read the x and y coordinates for each point
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> x [ i ] >> y [ i ];
    }
    
    // Call the solve function with the input values
    solve ( N, x, y );
    
    return 0;
}

