#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    // Use standard input and output
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Read the number of integers from input
    int n;
    std::cin >> n;

    // Initialize a set to store the integers (to remove duplicates)
    std::set<int> a;

    // Read n integers from input and add them to the set
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        a.insert(value);
    }

    // Convert the set back to a vector and sort it (set is already sorted)
    std::vector<int> sorted_a(a.begin(), a.end());

    // Initialize a flag to check for consecutive triplets
    bool found = false;

    // Check for three consecutive integers in the sorted vector
    for (size_t i = 0; i < sorted_a.size(); i++) {
        // Ensure there are at least three elements to check
        if (i + 2 < sorted_a.size()) {
            // Check if the current, next, and the one after next integers are consecutive
            if (sorted_a[i] + 1 == sorted_a[i + 1] && sorted_a[i + 1] + 1 == sorted_a[i + 2]) {
                found = true; // Set found to true if consecutive triplet is found
                break; // No need to check further
            }
        }
    }

    // Output "YES" if a triplet was found, otherwise output "NO"
    std::cout << (found ? "YES" : "NO") << std::endl;

    return 0;
}

// <END-OF-CODE>
