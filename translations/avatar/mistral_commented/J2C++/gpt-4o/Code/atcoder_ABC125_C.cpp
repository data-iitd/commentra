#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the greatest common divisor of two integers using Euclid's algorithm
int gcd(int a, int b) {
    if (b > a) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    int r;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0);
    return a;
}

int main() {
    int N;
    cin >> N; // Read the number of elements in the array A
    vector<int> A(N); // Allocate memory for the array A of size N

    // Read the elements of the array A from the standard input
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize vectors M, L, and R
    vector<int> L(N), R(N);

    // Initialize the first elements of L and R vectors
    L[0] = A[0];
    R[N - 1] = A[N - 1];

    // Calculate the gcd of consecutive pairs of elements in the array A,
    // starting from the second element, and store the results in the L vector
    for (int i = 1; i < N; i++) {
        L[i] = gcd(L[i - 1], A[i]);
    }

    // Calculate the gcd of consecutive pairs of elements in the array A,
    // starting from the last element, and store the results in the R vector
    for (int i = N - 2; i >= 0; i--) {
        R[i] = gcd(R[i + 1], A[i]);
    }

    // Find the maximum value among the gcd of consecutive pairs of elements
    // in the subarrays [0, i] and [i+1, N-1] for all i from 0 to N-2
    int answer = max(L[N - 2], R[1]);
    for (int i = 1; i < N - 1; i++) {
        answer = max(answer, gcd(L[i - 1], R[i + 1]));
    }

    // Print the result
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
