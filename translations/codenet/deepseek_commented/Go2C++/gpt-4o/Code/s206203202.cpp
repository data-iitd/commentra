#include <iostream>
#include <cstdlib> // for abs function
using namespace std;

// Abs returns the absolute value of an integer
int Abs(int x) {
    return (x < 0) ? -x : x;
}

// min returns the smaller of two integers
int min(int a, int b) {
    return (a > b) ? b : a;
}

int main() {
    int N, K;
    cin >> N >> K; // Read two integers from input

    int x;
    x = N % K; // Calculate the remainder of N divided by K

    x = min(Abs(x - K), x); // Calculate the minimum of the absolute difference and x itself
    cout << x << endl; // Print the result

    return 0;
}

// <END-OF-CODE>
