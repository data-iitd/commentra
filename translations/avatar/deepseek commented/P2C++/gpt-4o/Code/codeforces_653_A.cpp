#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;  // Take an integer input for the number of elements
    std::vector<int> l(n);  // Create a vector to hold the integers

    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];  // Take a list of integers as input
    }

    std::sort(l.begin(), l.end());  // Sort the list of integers

    std::unordered_set<int> s(l.begin(), l.end());  // Use a set for O(1) lookups

    // Check if there exists any integer i in the list such that i + 1 and i + 2 are also in the list
    for (int i : l) {
        if (s.count(i + 1) && s.count(i + 2)) {  // Check if i + 1 and i + 2 are in the set
            std::cout << "YES" << std::endl;  // If found, print 'YES' and break the loop
            return 0;  // Exit the program
        }
    }

    std::cout << "NO" << std::endl;  // If no such integer is found, print 'NO'
    return 0;
}

// <END-OF-CODE>
