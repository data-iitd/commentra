#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initialize variables and read input
    int N;
    std::cout << "Enter the number of elements in the array:" << std::endl;
    std::cin >> N;

    std::vector<int> A(N);
    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    // Sort the array in ascending order
    std::sort(A.begin(), A.end());

    // Calculate the answer
    int ans = 0;
    std::cout << "Calculating the answer..." << std::endl;
    for (int i = 1; i < N; i++) {
        ans += A[i] - A[i - 1];
    }

    // Print the answer
    std::cout << "The answer is: " << ans << std::endl;

    return 0;
}
