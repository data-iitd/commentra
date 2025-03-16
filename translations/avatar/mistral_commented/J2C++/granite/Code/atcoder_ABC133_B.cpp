

#include <bits/stdc++.h>  // Importing necessary libraries

using namespace std ;  // Using the standard namespace

int main ( ) {
    int N, D ;  // Declaring variables N and D to store the number of vectors and their dimensions respectively

    // Reading the number of vectors N and their dimensions D from user input
    cin >> N >> D ;

    // Creating a 2D integer array'vectors' of size N x D to store the vectors
    int vectors [ N ] [ D ] ;

    // Reading the components of each vector from user input and storing it in the'vectors' array
    for ( int i = 0 ; i < N ; i ++ ) {
        for ( int j = 0 ; j < D ; j ++ ) {
            cin >> vectors [ i ] [ j ] ;
        }
    }

    // Initializing the answer variable to 0
    int answer = 0 ;

    // Iterating through all pairs of vectors (i, j) where i < j
    for ( int i = 0 ; i < N - 1 ; i ++ ) {
        for ( int j = i + 1 ; j < N ; j ++ ) {

            // Calculating the Euclidean distance between the vectors i and j
            int dist = 0 ;
            for ( int d = 0 ; d < D ; d ++ ) {
                int x = vectors [ i ] [ d ] - vectors [ j ] [ d ] ;  // Difference between corresponding components
                dist += ( x * x ) ;  // Squaring the difference and adding to the distance
            }

            // Calculating the square root of the distance and checking if it is a perfect square
            double sq = sqrt ( dist ) ;
            answer += ( abs ( sq - floor ( sq ) ) < 0.001? 1 : 0 ) ;
        }
    }

    // Printing the final answer
    cout << answer << endl ;  // Printing the answer and ending the program

    return 0 ;  // Returning 0 to indicate successful execution
}

