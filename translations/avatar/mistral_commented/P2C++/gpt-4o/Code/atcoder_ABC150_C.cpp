#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

int main() {
    // Ask the user for the size of the permutation list
    int n;
    std::cin >> n;

    // Create a vector to hold the numbers from 1 to n
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        numbers[i] = i + 1;
    }

    // Create a vector to hold all possible permutations
    std::vector<std::vector<int>> orig;
    do {
        orig.push_back(numbers);
    } while (std::next_permutation(numbers.begin(), numbers.end()));

    // Ask the user for two permutations as vectors
    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
    }

    // Find the indices of p and q in the orig list
    auto pn = std::find(orig.begin(), orig.end(), p) - orig.begin();
    auto qn = std::find(orig.begin(), orig.end(), q) - orig.begin();

    // Print the absolute difference between the indices of p and q
    std::cout << std::abs(pn - qn) << std::endl;

    return 0;
}
// <END-OF-CODE>
