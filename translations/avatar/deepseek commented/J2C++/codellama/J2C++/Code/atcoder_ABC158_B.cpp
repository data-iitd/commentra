
#include <iostream> 
#include <cmath> 

using namespace std ; 

int main ( ) { 
    long N ; 
    long A ; 
    long B ; 
    long k = 0 ; 

    // Take input from the user
    cin >> N >> A >> B ; 

    // Check if the values of N, A, and B are within the specified ranges
    if ( 1 <= N && N <= pow ( 10 , 18 ) && 0 <= A && 0 <= B && 0 < A + B && A + B <= pow ( 10 , 18 ) ) { 

        // Calculate the number of complete cycles (k) of A and B that fit into N
        if ( A + B <= N ) { 
            k = N / ( A + B ) ; 
            if ( N - k * ( A + B ) > A ) { 
                cout << A * k + ( N - k * ( A + B ) ) - ( N - ( k * ( A + B ) + A ) ) << endl ; 
            } else { 
                cout << A * k + ( N - k * ( A + B ) ) << endl ; 
            } 
        } 
        // If the sum of A and B is greater than N and A is less than or equal to N
        else if ( A + B > N && A <= N ) { 
            cout << A << endl ; 
        } 
        // If none of the above conditions are met, print N
        else { 
            cout << N << endl ; 
        } 
    } 

    // End of code
    cout << "