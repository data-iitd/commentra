#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Read the number of elements
    int N;
    std::cin >> N;

    // Read the values into a vector
    std::vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> V[i];
    }

    // Read the costs into a vector
    std::vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> C[i];
    }

    // Initialize a variable to hold the total profit
    int ans = 0;

    // Iterate through each item
    for (int i = 0; i < N; ++i) {
        // Check if the value is greater than the cost
        if (V[i] - C[i] > 0) {
            // Calculate the profit and add it to the total profit
            ans += (V[i] - C[i]);
        }
    }

    // Print the total profit
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
