
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the number of elements N from input
    int N;
    std::cin >> N;

    // Initialize a vector A to hold N integers
    std::vector<int> A(N);
    
    // Read N integers from input into the vector A
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    // Sort the vector A in ascending order
    std::sort(A.begin(), A.end());

    // Initialize a variable to hold the total difference sum
    int ans = 0;
    
    // Calculate the sum of differences between consecutive elements in the sorted vector
    for (int i = 1; i < N; i++) {
        ans += A[i] - A[i-1];
    }

    // Output the total sum of differences
    std::cout << ans << std::endl;

    return 0;
}
