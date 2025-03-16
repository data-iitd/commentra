

#include <iostream>
#include <cmath>
using namespace std;

int task4 ( int A, int B, int n ) {
    // The function `task4` is designed to find the value of `X` such that `A * (X ** n) == B`.
    for ( int X = - 1000 ; X <= 1000 ; X ++ ) {
        // It iterates over the range from -1000 to 1000 for `X`.
        if ( A * pow ( X, n ) == B ) {
            // For each value of `X`, it checks if the equation `A * (X ** n) == B` holds true.
            return X;
            // If a solution is found, it returns the value of `X`.
    }
    return - 1;
    // If no solution is found after the loop, it returns -1.
}

int main ( ) {
    int A, B, n;
    cin >> A >> B >> n;
    // The main part of the code takes input for `A`, `B`, and `n`.
    cout << task4 ( A, B, n ) << endl;
    // Converts them to integers, and calls the `task4` function.
    // Finally, it prints the result returned by the `task4` function.
    return 0;
}
