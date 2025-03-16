
#include <iostream> // Including the necessary header file for input/output operations

using namespace std; // Using the standard namespace for input/output operations

int main ( ) { // Defining the main function
    int N, L, R, QL, QR; // Declaring the integer variables N, L, R, QL, and QR to store the input values

    cin >> N >> L >> R >> QL >> QR; // Reading the input values from the console

    int W [ N ] ; // Declaring an integer array W of size N to store the input values
    int sum [ N + 1 ] ; // Declaring an integer array sum of size N+1 to store the cumulative sum of the elements in the array W

    for ( int n = 0 ; n < N ; n ++ ) { // Iterating through each element in the array W
        cin >> W [ n ] ; // Reading the integer value of each element in the array W
        sum [ n + 1 ] = sum [ n ] + W [ n ] ; // Calculating the sum of all elements from 0 to n+1
    }

    long min = LLONG_MAX ; // Initializing the minimum value to be the maximum long value

    for ( int firstR = 0 ; firstR <= N ; firstR ++ ) { // Iterating through all possible starting indices for the right segment
        int lCount = firstR ; // The length of the left segment is equal to the index of the starting point of the right segment
        int rCount = N - lCount ; // The length of the right segment is equal to the total length of the array minus the length of the left segment

        long cand = sum [ lCount ] * L + ( sum [ N ] - sum [ lCount ] ) * R ; // Calculating the candidate value for the current combination of left and right segments

        int llCount = max ( 0, lCount - rCount - 1 ) ; // Calculating the length of the overlapping part between the left and right segments, if any
        int rrCount = max ( 0, rCount - lCount - 1 ) ; // Calculating the length of the overlapping part between the right and left segments, if any

        cand += llCount * QL ; // Adding the contribution of the left overlapping part to the candidate value
        cand += rrCount * QR ; // Adding the contribution of the right overlapping part to the candidate value

        min = min ( cand, min ) ; // Updating the minimum value if the current candidate value is smaller
    }

    cout << min << endl; // Printing the minimum value as the output

    return 0; // Returning 0 to indicate successful execution of the program
}

