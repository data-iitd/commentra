#include <iostream>
#include <string>

using namespace std;

void solve(string S, string T, int A, int B, string U) {
    // Check if the first string S matches the string U
    if (S == U) {
        A--;  // Decrement A if S matches U
    }
    // Check if the second string T matches the string U
    if (T == U) {
        B--;  // Decrement B if T matches U
    }
    // Print the final values of A and B
    cout << A << " " << B << endl;
    return;
}

int main() {
    // Read the first string S from input
    string S;
    cin >> S;
    // Read the second string T from input
    string T;
    cin >> T;
    // Read the integer A from input and convert it to an integer
    int A;
    cin >> A;
    // Read the integer B from input and convert it to an integer
    int B;
    cin >> B;
    // Read the string U from input
    string U;
    cin >> U;
    
    // Call the solve function with the read values
    solve(S, T, A, B, U);
    return 0;
}

