#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to read input from standard input in buffer
vector<int> read() {
    int N, d, x;
    cin >> N >> d >> x;
    return {N, d, x};
}

// Function definition: main function takes three arguments N, d, and x
int main(int argc, char* argv[]) {
    // Reading input as three integers: N, d, and x
    vector<int> inputs = read();
    int N = inputs[0];
    int d = inputs[1];
    int x = inputs[2];

    // Initializing the result variable to 0
    double ret = 0;

    // Loop continues as long as N is greater than 0
    while (N > 0) {
        // Adding the current term to the result
        ret += d + (N - 0.5) * x;

        // Updating the value of d for the next iteration
        d += d / N + (5 * x) / (2 * N);

        // Updating the value of x for the next iteration
        x += 2 * x / N;

        // Decrementing the value of N for the next iteration
        N -= 1;
    }

    // Returning the final result
    cout << ret << endl;

    return 0;
}
