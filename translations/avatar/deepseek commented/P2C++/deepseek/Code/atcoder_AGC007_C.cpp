#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the result based on N, d, and x
double main(int N, double d, double x) {
    double ret = 0.0;  // Initializing the result variable to accumulate the result
    while (N > 0) {  // Running the loop while N is greater than 0
        // Incrementing ret by the sum of d and (N - 0.5) * x
        ret += d + (N - 0.5) * x;
        
        // Updating the value of d using a complex formula
        d = d + (d / N) + (5 * x) / (2 * N);
        
        // Updating the value of x using another formula
        x += 2 * x / N;
        
        // Decrementing N by 1
        N -= 1;
    }
    
    // Returning the accumulated result
    return ret;
}

int main() {
    int N, d, x;
    
    // Reading the values of N, d, and x from standard input
    cin >> N >> d >> x;
    
    // Printing the result of the main function
    cout << main(N, d, x) << endl;
    
    return 0;
}
