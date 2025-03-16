#include <iostream>
#include <vector>

int main() {
    // Declare an integer N to hold the size of the arrays
    int N;
    // Read the size of the arrays from user input
    std::cin >> N;

    // Declare a vector A of size N+1 and a vector B of size N
    std::vector<int> A(N + 1);
    std::vector<int> B(N);
    
    // Read N+1 integers into vector A from user input
    for (int i = 0; i < N + 1; i++) {
        std::cin >> A[i];
    }

    // Read N integers into vector B from user input
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    // Initialize a variable to hold the total answer
    long ans = 0;

    // Loop through each index of the vectors to calculate the answer
    for (int i = 0; i < N; i++) {
        // Handle the case for site i
        if (A[i] >= B[i]) {
            // If A[i] can satisfy B[i], add B[i] to the answer
            ans += B[i];
            // Decrease A[i] by B[i] and set B[i] to 0
            A[i] -= B[i];
            B[i] = 0;
        } else {
            // If A[i] cannot satisfy B[i], add A[i] to the answer
            ans += A[i];
            // Decrease B[i] by A[i] and set A[i] to 0
            B[i] -= A[i];
            A[i] = 0;
        }

        // Handle the case for site i + 1
        if (A[i + 1] >= B[i]) {
            // If A[i + 1] can satisfy B[i], add B[i] to the answer
            ans += B[i];
            // Decrease A[i + 1] by B[i] and set B[i] to 0
            A[i + 1] -= B[i];
            B[i] = 0;
        } else {
            // If A[i + 1] cannot satisfy B[i], add A[i + 1] to the answer
            ans += A[i + 1];
            // Decrease B[i] by A[i + 1] and set A[i + 1] to 0
            B[i] -= A[i + 1];
            A[i + 1] = 0;
        }
    }

    // Print the final answer
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
