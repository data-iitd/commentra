#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
    // Read an integer input which represents the number of elements in the list
    int n;
    std::cin >> n;

    // Read the elements into a vector
    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }

    // Sort the vector in ascending order
    std::sort(l.begin(), l.end());

    // Use a set for quick lookup
    std::unordered_set<int> elements(l.begin(), l.end());

    // Iterate through each element in the sorted vector
    for (int i : l) {
        // Check if both i + 1 and i + 2 exist in the set
        if (elements.count(i + 1) > 0 && elements.count(i + 2) > 0) {
            // If the condition is met, print 'YES' and exit the loop
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    // If the loop completes without finding the condition, print 'NO'
    std::cout << "NO" << std::endl;

    return 0;
}
// <END-OF-CODE>
