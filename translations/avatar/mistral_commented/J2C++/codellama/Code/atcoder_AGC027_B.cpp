
#include <iostream>
#include <cmath>

using namespace std ; // Using the standard namespace

int main ( ) { // Main method to start the program
    int N ; // Declaring the number of elements in the array
    long X ; // Declaring the value of X
    long x [ ] ; // Declaring an array to store the elements
    long xsum [ ] ; // Declaring an array to store the sum of elements up to that index

    cin >> N >> X ; // Reading the number of elements in the array and the value of X from the console

    x = new long [ N ] ; // Creating an array of size N to store the elements
    xsum = new long [ N + 1 ] ; // Creating an array of size N+1 to store the sum of elements up to that index

    for ( int i = 0 ; i < N ; i ++ ) { // Loop to read and store the elements in the array
        cin >> x [ i ] ;
        xsum [ i + 1 ] = xsum [ i ] + x [ i ] ; // Updating the sum of elements up to the current index
    }

    long ans = X * N + 5 * xsum [ N ] ; // Initializing the answer with the first calculation

    for ( int i = 1 ; i < N ; i ++ ) { // Loop to find the minimum cost
        long cost = X * i + 5 * ( xsum [ N ] - xsum [ N - i ] ) ; // Calculating the cost for the current i
        for ( int j = 5 , k = N - i ; k >= 0 ; j += 2 , k -= i ) { // Nested loop to check the cost for different j and k
            if ( cost > ans ) { // If the cost is greater than the current answer, break the loop
                break ;
            }
            cost += j * ( xsum [ k ] - xsum [ max ( k - i , 0 ) ] ) ; // Updating the cost with the sum of elements between k and k-i
        }
        ans = min ( ans , cost ) ; // Updating the answer with the minimum cost found so far
    }

    cout << ans + N * X << endl ; // Printing the final answer

    return 0 ; // Returning 0 to indicate that the program executed successfully
}

