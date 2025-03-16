#include <iostream>
#include <string>

using namespace std;

void solve(string S, string T, int A, int B, string U) {
    // Check if the string S is equal to the string U
    if (S == U) {
        // Decrement the count of A by 1
        A -= 1;
    }
    // Check if the string T is equal to the string U
    if (T == U) {
        // Decrement the count of B by 1
        B -= 1;
    }
    // Print the updated counts of A and B
    cout << A << " " << B << endl;
}

int main() {
    string S, T, U;
    int A, B;

    // Read the string S
    cin >> S;
    // Read the string T
    cin >> T;
    // Read the integer A
    cin >> A;
    // Read the integer B
    cin >> B;
    // Read the string U
    cin >> U;

    // Call the solve function with the read inputs
    solve(S, T, A, B, U);

    return 0;
}

// <END-OF-CODE>
