#include <iostream>
#include <algorithm> // for std::max

// The main function is the entry point of the program.
int main() {
    // Initialize two integers A and B.
    int A, B;

    // Read two integers A and B from the standard input.
    std::cin >> A >> B;

    // Calculate the maximum value of A+B, A-B, and A*B using the max function.
    int mx = std::max(A + B, A - B);
    mx = std::max(mx, A * B);

    // Print the maximum value.
    std::cout << mx << std::endl;

    return 0;
}

// <END-OF-CODE>
