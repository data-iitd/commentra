#include <iostream>
#include <vector>
#include <numeric> // for std::gcd
using namespace std;

// Function to calculate the GCD of two integers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    // Ask the user for the number of elements in the list
    int N;
    cin >> N;

    // Get a list of integers from the user input
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Use std::accumulate to calculate the GCD of all integers in the list A
    int result = A[0];
    for (int i = 1; i < N; ++i) {
        result = gcd(result, A[i]);
    }

    // Print the result, which is the GCD of all the integers in the list A
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
