#include <iostream>
using namespace std;

// Function to read a single integer from standard input
int ri() {
    int x;
    cin >> x;
    return x;
}

int main() {
    // Read the number of test cases from standard input
    int N = ri();

    // Initialize the answer to 0
    long long ans = 0;

    // Iterate through all numbers from 1 to N
    for (int i = 1; i <= N; ++i) {
        // Calculate the contribution of i to the answer
        // The formula is given by the problem statement
        ans += i * (N / i) * (N / i + 1) / 2;
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
