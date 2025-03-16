#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    // Generate all possible permutations of the numbers from 1 to n
    std::vector<std::vector<int>> orig;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    do {
        orig.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));

    // Read the first permutation input as a vector of integers
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    // Read the second permutation input as a vector of integers
    std::vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
    }

    // Find the index of the first permutation in the list of all permutations
    int pn = -1, qn = -1;
    for (int i = 0; i < orig.size(); ++i) {
        if (orig[i] == p) {
            pn = i;
        }
        if (orig[i] == q) {
            qn = i;
        }
    }

    // Calculate and print the absolute difference between the two indices
    std::cout << std::abs(pn - qn) << std::endl;

    return 0;
}
