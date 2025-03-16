#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

const double inf = 1e12; // Constants should be defined with clear names and values

int main() {
    // Initialize variables and read input
    int n;
    std::cin >> n;

    std::vector<int> arrA(n); // Create a vector of size n to store input
    for (int i = 0; i < n; i++) {
        std::cin >> arrA[i]; // Read each element of the vector
    }

    std::vector<int> cumSumA(n + 1); // Create a vector of size n+1 to store cumulative sum
    cumSumA[0] = 0; // Initialize the first element of cumulative sum vector
    for (int i = 0; i < n; i++) { // Iterate through the vector and calculate cumulative sum
        cumSumA[i + 1] = cumSumA[i] + arrA[i];
    }

    // Initialize variable to store the answer
    double ans = inf; // Initialize with a large value

    // Iterate through the vector to find the answer
    for (int i = 1; i < n; i++) {
        double temp = cumSumA[n] - cumSumA[i] * 2; // Calculate the difference
        if (std::abs(temp) < ans) { // If the difference is smaller than the current answer
            ans = temp; // Update the answer
        }
    }

    // Print the answer
    std::cout << static_cast<int>(ans) << std::endl;

    // End of the code
}
