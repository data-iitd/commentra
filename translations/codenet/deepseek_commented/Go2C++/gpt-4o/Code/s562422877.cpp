#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the number of elements N
    int N;
    std::cin >> N;

    // Create a vector A to store N integers
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        // Read each integer and store it in vector A
        std::cin >> A[i];
    }

    // Sort the vector A in ascending order
    std::sort(A.begin(), A.end());

    // Initialize the answer variable to store the result
    int ans = 0;
    for (int i = 1; i < N; i++) {
        // Calculate the sum of differences between consecutive elements
        ans += A[i] - A[i - 1];
    }

    // Print the result
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
