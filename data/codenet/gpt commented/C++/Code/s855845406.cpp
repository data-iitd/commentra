#include <iostream>

int main() {
    // Declare variables to hold input values
    int N, A;

    // Read an integer value for N from standard input
    std::cin >> N;

    // Read an integer value for A from standard input
    std::cin >> A;

    // Calculate the result by squaring N and subtracting A, then output the result
    std::cout << N * N - A << std::endl;

    return 0; // Indicate that the program ended successfully
}
