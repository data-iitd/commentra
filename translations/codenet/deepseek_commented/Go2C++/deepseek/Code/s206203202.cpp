#include <iostream>
#include <cmath> // Include cmath for std::abs

// Function to calculate the absolute value of an integer
int Abs(int x) {
    return std::abs(x);
}

// Function to return the smaller of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int N, K;
    std::cin >> N >> K; // Read two integers from input

    int x = N % K; // Calculate the remainder of N divided by K

    x = min(Abs(x - K), x); // Calculate the minimum of the absolute difference and x itself
    std::cout << x << std::endl; // Print the result

    return 0;
}

