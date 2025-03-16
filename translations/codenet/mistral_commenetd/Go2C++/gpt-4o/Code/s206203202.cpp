// Include necessary header files
#include <iostream>
#include <cstdlib> // for abs function

// Function to return the absolute value of an integer
int Abs(int x) {
    if (x < 0) {
        // If the input integer is negative, return its negation
        return -x;
    }
    // Otherwise, return the input integer as it is
    return x;
}

// Function to return the minimum of two integers
int min(int a, int b) {
    if (a > b) {
        // If the first integer is greater than the second, return the second
        return b;
    }
    // Otherwise, return the first integer
    return a;
}

// Main function is the entry point of the program
int main() {
    // Declare and initialize two integer variables, N and K, using std::cin
    int N, K;
    std::cin >> N >> K;

    // Declare and initialize an integer variable, x, with the value of N modulo K
    int x = N % K;

    // Call the Abs function to get the absolute value of x if it's negative
    x = Abs(x);

    // Call the min function to find the minimum between x and Abs(x-K)
    x = min(Abs(x - K), x);

    // Print the result using std::cout
    std::cout << x << std::endl;

    return 0;
}

// <END-OF-CODE>
