#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read an integer N from user input
    int N;
    std::cin >> N;

    // Create a vector A where each element is calculated as (input value * N + index)
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        int inputValue;
        std::cin >> inputValue;
        A[i] = inputValue * N + i;
    }

    // Sort the vector A in ascending order
    std::sort(A.begin(), A.end());

    // Initialize a counter to keep track of mismatches
    int cnt = 0;

    // Iterate through each element in the sorted vector A
    for (int i = 0; i < N; ++i) {
        // Calculate the value of d as the remainder of A[i] divided by N, then take that remainder modulo 2
        int d = (A[i] % N) % 2;

        // Check if the parity of d does not match the parity of the current index i
        if (d % 2 != i % 2) {
            // If they don't match, increment the counter
            cnt++;
        }
    }

    // Print half of the count of mismatches, as each mismatch can be paired
    std::cout << cnt / 2 << std::endl;

    return 0;
}

// <END-OF-CODE>
