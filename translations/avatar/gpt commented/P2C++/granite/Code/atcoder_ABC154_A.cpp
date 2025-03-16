
#include <iostream>
#include <string>

void solve(const std::string& S, const std::string& T, int& A, int& B, const std::string& U) {
    // Check if the first string S matches the string U
    if (S == U) {
        A -= 1;  // Decrement A if S matches U
    }
    // Check if the second string T matches the string U
    if (T == U) {
        B -= 1;  // Decrement B if T matches U
    }
    // Print the final values of A and B
    std::cout << A << " " << B << std::endl;
}

int main() {
    std::string S, T, U;
    int A, B;
    // Read the first string S from input
    std::cin >> S;
    // Read the second string T from input
    std::cin >> T;
    // Read the integer A from input and convert it to an integer
    std::cin >> A;
    // Read the integer B from input and convert it to an integer
    std::cin >> B;
    // Read the string U from input
    std::cin >> U;
    
    // Call the solve function with the read values
    solve(S, T, A, B, U);
    
    return 0;
}

