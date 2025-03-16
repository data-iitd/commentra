#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;  // Read the number of elements in the list
    std::vector<int> l(n);  // Create a vector to hold the integers

    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];  // Read the list of integers
    }

    std::sort(l.begin(), l.end());  // Sort the list in ascending order

    std::unordered_set<int> elements(l.begin(), l.end());  // Create a set for quick lookup

    for (int i : l) {  // Iterate through each element in the sorted list
        if (elements.count(i + 1) && elements.count(i + 2)) {  // Check if the next two elements are also in the set
            std::cout << "YES" << std::endl;  // If yes, print 'YES' and break out of the loop
            return 0;  // Exit the program
        }
    }

    std::cout << "NO" << std::endl;  // If no, print 'NO' after the loop finishes
    return 0;
}

// <END-OF-CODE>
