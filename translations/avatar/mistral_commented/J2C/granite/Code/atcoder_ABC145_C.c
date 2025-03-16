
#include <stdio.h> // Include the standard input/output library
#include <math.h> // Include the math library for mathematical functions

int main ( void ) { // Starting point of the program
    int N ; // Declare the variable N to store the number of points
    scanf ( "%d", & N ) ; // Read the number of points from the user using scanf

    int pos [ N ] [ 2 ] ; // Declare a 2D array of size N x 2 to store the x and y coordinates of the points

    for ( int i = 0 ; i < N ; i ++ ) { // Iterate through each point
        scanf ( "%d %d", & pos [ i ] [ 0 ], & pos [ i ] [ 1 ] ) ; // Read the x and y coordinates of the point using scanf
    }

    double sum = 0 ; // Initialize the sum variable to 0

    for ( int i = 0 ; i < N ; i ++ ) { // Iterate through each point
        for ( int j = 0 ; j < N ; j ++ ) { // Iterate through all other points except the current one
            if ( i == j ) continue ; // Skip the current point when comparing it with itself
            sum += dist ( pos [ i ] [ 0 ], pos [ i ] [ 1 ], pos [ j ] [ 0 ], pos [ j ] [ 1 ] ) ; // Add the distance between the current and the other point to the sum
        }
    }

    printf ( "%lf", sum / N ) ; // Print the average distance between all pairs of points using printf

    return 0 ; // Return 0 to indicate successful execution of the program
}

double dist ( int x1, int y1, int x2, int y2 ) { // Define the dist function to calculate the Euclidean distance between two points
    return sqrt ( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) ) ; // Return the calculated distance
}

