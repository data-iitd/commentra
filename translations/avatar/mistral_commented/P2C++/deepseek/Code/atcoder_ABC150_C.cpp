#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int main() {
    int n;
    std::cin >> n;

    // Create a vector of all possible permutations of numbers from 1 to n
    std::vector<std::vector<int>> orig;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    do {
        orig.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));

    // Ask the user for two permutations as vectors
    std::vector<int> p(n);
    std::vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
    }

    // Find the indices of p and q in the orig vector
    int pn = -1, qn = -1;
    for (int i = 0; i < orig.size(); ++i) {
        if (orig[i] == p) {
            pn = i;
        }
        if (orig[i] == q) {
            qn = i;
        }
    }

    // Print the absolute difference between the indices of p and q
    std::cout << std::abs(pn - qn) << std::endl;

    return 0;
}
