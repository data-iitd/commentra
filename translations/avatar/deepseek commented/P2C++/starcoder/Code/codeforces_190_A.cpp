
#include <iostream>
using namespace std;

int main ( ) {
    int n, m ;
    cin >> n >> m ;
    // Taking input for two integers, `n` and `m`, separated by spaces
    if ( n < 1 ) {
        // Check if `n` is less than 1
        if ( m < 1 ) {
            // Check if `m` is also less than 1
            cout << n << " " << m << endl ;
            // Print `n` and `m` and then quit the program
            return 0 ;
            // Return 0 to end the program
        }
        cout << "Impossible" << endl ;
        // Print "Impossible" and then quit the program
        return 0 ;
        // Return 0 to end the program
    }
    if ( m > n ) {
        // Check if `m` is greater than `n`
        int min = m, max = n + m - 1 ;
        cout << min << " " << max << endl ;
        // Calculate `min` as `m` and `max` as `n + m - 1`, then print `min` and `max`
    }
    if ( m <= n ) {
        // Check if `m` is less than or equal to `n`
        int min = n, max = n + m - 1 ;
        if ( m == 0 ) {
            max = n ;
        }
        cout << min << " " << max << endl ;
        // Calculate `min` as `n` and `max` as `n + m - 1`. If `m` is 0, set `max` to `n`. Finally, print `min` and `max`
    }
    return 0 ;
    // Return 0 to end the program
}

