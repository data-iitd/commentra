
#include <iostream> // We include the iostream library to use the standard input and output streams

using namespace std ; // We use the std namespace to avoid writing std:: before the names of the standard library functions and objects

int main ( ) { // The main function is the entry point of the program
    int n ; // We declare an integer variable n to store the number of terms
    long long ans = 0 ; // We initialize a long long variable ans to 0, which will be used to store the answer

    // We read an integer n from the standard input stream using the cin object
    cin >> n ;

    for ( int i = 1 ; i < n + 1 ; i ++ ) { // We start a for loop that iterates from 1 to n
        ans += ( long long ) i * ( ( long long ) n / ( long long ) i ) * ( ( ( long long ) n / ( long long ) i ) + 1 ) / 2 ; // In each iteration of the loop, we calculate the contribution of i to the answer using the formula i * (n / i) * ((n / i) + 1) / 2 and add it to the ans variable
    }

    cout << ans << endl ; // After the loop finishes, we print the value of ans to the standard output stream using the cout object

    return 0 ; // We return 0 to indicate successful execution of the program
}

