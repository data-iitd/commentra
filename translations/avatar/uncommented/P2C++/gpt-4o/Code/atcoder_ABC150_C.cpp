#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    // Generate all permutations of numbers from 1 to n
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        numbers[i] = i + 1;
    }

    std::vector<std::vector<int>> orig;
    do {
        orig.push_back(numbers);
    } while (std::next_permutation(numbers.begin(), numbers.end()));

    // Read the two permutations
    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
    }

    // Find the indices of p and q in orig
    auto pn = std::find(orig.begin(), orig.end(), p) - orig.begin();
    auto qn = std::find(orig.begin(), orig.end(), q) - orig.begin();

    // Output the absolute difference of the indices
    std::cout << std::abs(pn - qn) << std::endl;

    return 0;
}

// <END-OF-CODE>
