#include <iostream>
#include <string>

using namespace std;

// Define a function named 'solve' that takes five arguments: S, T, A, B, and U.
void solve(string S, string T, int A, int B, string U) {
    // Check if S is equal to U. If yes, decrement A.
    if (S == U) {
        A--;
    }

    // Check if T is equal to U. If yes, decrement B.
    if (T == U) {
        B--;
    }

    // Print the updated values of A and B.
    cout << A << " " << B << endl;
}

// Define a function named 'main' that doesn't take any arguments.
int main() {
    string S, T, U;
    int A, B;

    // Read input values for S, T, A, B, and U.
    cin >> S >> T >> A >> B >> U;

    // Call the 'solve' function with the assigned variables.
    solve(S, T, A, B, U);

    return 0;
}

// <END-OF-CODE>
