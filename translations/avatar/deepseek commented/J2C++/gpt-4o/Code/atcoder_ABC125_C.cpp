#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the GCD of two numbers
int gcd(int a, int b) {
    if (b > a) { // Ensure a is greater than b
        swap(a, b);
    }
    if (b == 0) { // Base case for GCD
        return a;
    }
    int r;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0); // Continue until r is 0
    return a;
}

int main() {
    int N;
    cin >> N; // Read the number of elements
    vector<int> A(N); // Initialize the array A with size N

    // Read the elements of A from the input
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Arrays to store the prefix and suffix GCDs
    vector<int> L(N);
    vector<int> R(N);

    // Calculate the prefix GCD array L
    L[0] = A[0];
    for (int i = 1; i < N; i++) {
        L[i] = gcd(L[i - 1], A[i]);
    }

    // Calculate the suffix GCD array R
    R[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        R[i] = gcd(R[i + 1], A[i]);
    }

    // Initialize the answer with the maximum of the GCD of the first and last elements of L and R
    int answer = max(L[N - 2], R[1]);

    // Iterate through the array to find the maximum GCD
    for (int i = 1; i < N - 1; i++) {
        answer = max(answer, gcd(L[i - 1], R[i + 1]));
    }

    // Print the final answer
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
