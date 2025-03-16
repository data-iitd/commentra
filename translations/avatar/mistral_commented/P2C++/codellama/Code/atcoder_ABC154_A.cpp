#include <iostream>
#include <string>

// Define a function named 'solve' that takes five arguments: S, T, A, B, and U.
void solve(std::string S, std::string T, int A, int B, std::string U) {

    // Check if S is equal to U. If yes, decrement A.
    if (S == U) {
        A -= 1;
    }

    // Check if T is equal to U. If yes, decrement B.
    if (T == U) {
        B -= 1;
    }

    // Print the updated values of A and B.
    std::cout << A << " " << B << std::endl;

    // Return from the function.
    return;
}

// Define a function named 'main' that doesn't take any arguments.
int main() {

    // Define an inner function named 'iterate_tokens' that generates tokens from the standard input.
    auto iterate_tokens = [&]() {
        std::string word;
        while (std::cin >> word) {
            yield word;
        }
    };

    // Assign the next token to variables S, T, A, B, and U.
    std::string S = next(iterate_tokens());
    std::string T = next(iterate_tokens());
    int A = std::stoi(next(iterate_tokens()));
    int B = std::stoi(next(iterate_tokens()));
    std::string U = next(iterate_tokens());

    // Call the 'solve' function with the assigned variables.
    solve(S, T, A, B, U);

    // Return from the function.
    return 0;
}

// 