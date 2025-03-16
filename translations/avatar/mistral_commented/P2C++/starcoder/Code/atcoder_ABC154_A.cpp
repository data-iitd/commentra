#include <iostream>
#include <string>

using namespace std;

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

int main() {

    // Define variables.
    string S, T, U;
    int A, B;

    // Read input from stdin.
    cin >> S >> T >> A >> B >> U;

    // Call the'solve' function.
    solve(S, T, A, B, U);

    // Return from the function.
    return 0;
}

