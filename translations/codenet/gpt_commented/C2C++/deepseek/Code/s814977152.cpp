#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

// Comparison function for sort to sort integers
bool miyukiti(int asumisu, int mizuhasu) {
    return asumisu < mizuhasu;
}

// Main function
int main() {
    int N; // Number of elements
    std::vector<int> A; // Vector to hold input elements

    // Read the number of elements
    std::cin >> N;

    // Read the elements into vector A
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Copy vector A to a vector for sorting
    std::vector<int> tomatu = A;

    // Sort the vector of elements
    std::sort(tomatu.begin(), tomatu.end(), miyukiti);

    // Remove duplicates from the sorted vector
    auto last = std::unique(tomatu.begin(), tomatu.end());
    tomatu.erase(last, tomatu.end());

    // Track occurrences of each element in the original vector
    std::unordered_map<int, bool> mikakosi;
    for (int num : A) {
        mikakosi[num] = !mikakosi[num]; // Toggle occurrence
    }

    // Count the number of unique elements
    int emirinn = 0;
    for (const auto& pair : mikakosi) {
        if (pair.second) emirinn++; // Increment count for unique occurrences
    }

    // Output the count of unique elements
    std::cout << emirinn << std::endl;
    return 0; // Successful execution
}
