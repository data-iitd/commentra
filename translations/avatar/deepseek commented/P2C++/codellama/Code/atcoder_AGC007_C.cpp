#include <iostream>
#include <cmath>

using namespace std;

// Defining the main function to calculate a result based on N, d, and x
int main() {
    // Reading the values of N, d, and x from standard input
    int N, d, x;
    cin >> N >> d >> x;
    
    // Initializing the result variable to accumulate the result
    int ret = 0;
    
    // Running the loop while N is greater than 0
    while (N > 0) {
        // Incrementing ret by the sum of d and (N - 0.5) * x
        ret += d + (N - 0.5) * x;
        
        // Updating the value of d using a complex formula
        d += d / N + 5 * x / (2 * N);
        
        // Updating the value of x using another formula
        x += 2 * x / N;
        
        // Decrementing N by 1
        N--;
    }
    
    // Returning the accumulated result
    cout << ret << endl;
    
    // Ending the code
    return 0;
}

