#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Define a function named 'solve' that takes five arguments: S, T, A, B, and U.
void solve(const string& S, const string& T, int& A, int& B, const string& U) {

    // Check if S is equal to U. If yes, decrement A.
    if (S == U) {
        A -= 1;
    }

    // Check if T is equal to U. If yes, decrement B.
    if (T == U) {
        B -= 1;
    }

    // Print the updated values of A and B.
    cout << A << " " << B << endl;
}

// Define a function named 'main' that doesn't take any arguments.
int main() {

    // Declare variables to hold the input values.
    string S, T, U;
    int A, B;

    // Read the input values from standard input.
    cin >> S >> T >> A >> B;
    cin >> U;

    // Call the 'solve' function with the input values.
    solve(S, T, A, B, U);

    return 0;
}

