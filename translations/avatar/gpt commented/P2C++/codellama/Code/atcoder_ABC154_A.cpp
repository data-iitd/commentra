#include <iostream>
#include <string>

using namespace std;

void solve(string S, string T, int A, int B, string U) {
    // Check if the first string S matches the string U
    if (S == U) {
        A -= 1;  // Decrement A if S matches U
    }
    // Check if the second string T matches the string U
    if (T == U) {
        B -= 1;  // Decrement B if T matches U
    }
    // Print the final values of A and B
    cout << A << " " << B << endl;
    return;
}

int main() {
    // Define a generator function to iterate over tokens from standard input
    auto iterate_tokens() {
        string line;
        while (getline(cin, line)) {
            for (auto word : line) {
                yield word;
            }
        }
    }

    // Create a generator for tokens
    auto tokens = iterate_tokens();
    // Read the first string S from input
    string S = next(tokens);
    // Read the second string T from input
    string T = next(tokens);
    // Read the integer A from input and convert it to an integer
    int A = stoi(next(tokens));
    // Read the integer B from input and convert it to an integer
    int B = stoi(next(tokens));
    // Read the string U from input
    string U = next(tokens);

    // Call the solve function with the read values
    solve(S, T, A, B, U);

    return 0;
}

// END-OF-CODE
