

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;  // Take an integer input for the number of elements
    std::vector<int> l(n);  // Create a vector of integers with size n
    for (int i = 0; i < n; i++) {
        std::cin >> l[i];  // Take a list of integers as input
    }
    std::sort(l.begin(), l.end());  // Sort the vector of integers

    // Check if there exists any integer i in the vector such that i + 1 and i + 2 are also in the vector
    for (int i = 0; i < n; i++) {
        if (std::binary_search(l.begin(), l.end(), i + 1) && std::binary_search(l.begin(), l.end(), i + 2)) {  // Check if i + 1 and i + 2 are in the vector
            std::cout << "YES" << std::endl;  // If found, print 'YES' and break the loop
            break;
        }
    }
    if (i == n) {
        std::cout << "NO" << std::endl;  // If no such integer is found, print 'NO'
    }

    return 0;
}
