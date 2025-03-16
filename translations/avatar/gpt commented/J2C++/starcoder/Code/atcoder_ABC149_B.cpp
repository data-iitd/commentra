#include <iostream>
using namespace std;

int main() {
    // Declare variables to hold the values of A, B, K, and the results x, y
    long A, B, K; 
    long x, y; 

    // Set up input reading from standard input with UTF-8 encoding
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(ios::badbit);

    // Read a line of input, split it into tokens, and parse them as long integers
    cin >> A >> B >> K; 

    // Perform calculations based on the input values
    x = A - K; 
    if (x < 0) {
        y = B + x; 
        x = 0; 
        if (y < 0) {
            y = 0; 
        } 
    } 

    // Display the results of the calculations
    cout << x << " " << y << endl; 

    return 0;
}

