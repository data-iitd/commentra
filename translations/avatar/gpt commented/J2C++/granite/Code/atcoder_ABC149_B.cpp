
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <ctime> 
#include <queue> 
#include <set> 
#include <map> 
#include <stack> 
#include <bitset> 
using namespace std; 

int main() {
    // Declare variables to hold the values of A, B, K, and the results x, y
    long long A, B, K; 
    long long x, y; 

    // Read input values A, B, and K from the standard input
    cin >> A >> B >> K; 

    // Perform calculations based on the input values
    x = A; 
    y = B; 
    x = A - K; 

    // Check if the result x is negative
    if (x < 0) {
        // If x is negative, adjust y by adding the negative value of x to B
        y = B + x; 
        // Set x to 0 since it cannot be negative
        x = 0; 

        // Ensure y is not negative
        if (y < 0) {
            y = 0; 
        } 
    } 

    // Display the results of the calculations
    cout << x << " " << y << endl; 

    return 0; 
}
