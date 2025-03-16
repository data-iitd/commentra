
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read an integer input n, which defines the range of numbers to permute
    int n;
    std::cin >> n;

    // Generate all possible permutations of the numbers from 1 to n
    std::vector<std::vector<int>> orig(n);
    for (int i = 0; i < n; i++) {
        orig[i].resize(n);
        for (int j = 0; j < n; j++) {
            orig[i][j] = j + 1;
        }
    }
    std::vector<std::vector<int>> all_permutations;
    do {
        all_permutations.push_back(orig);
    } while (std::next_permutation(orig.begin(), orig.end()));

    // Read the first permutation input as a vector of integers
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    // Read the second permutation input as a vector of integers
    std::vector<int> q(n);
    for (int i = 0; i < n; i++) {
        std::cin >> q[i];
    }

    // Find the index of the first permutation in the list of all permutations
    int pn = -1;
    for (int i = 0; i < all_permutations.size(); i++) {
        if (all_permutations[i] == p) {
            pn = i;
            break;
        }
    }

    // Find the index of the second permutation in the list of all permutations
    int qn = -1;
    for (int i = 0; i < all_permutations.size(); i++) {
        if (all_permutations[i] == q) {
            qn = i;
            break;
        }
    }

    // Calculate and print the absolute difference between the two indices
    std::cout << std::abs(pn - qn) << std::endl;

    return 0;
}
