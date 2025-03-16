#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cout << "Enter the number of tuples: ";
    std::cin >> n;

    std::vector<std::pair<int, int>> m(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter tuple " << (i + 1) << ": ";
        std::cin >> m[i].first >> m[i].second;
    }

    // Sort the vector in descending order based on the first element of the pairs
    std::sort(m.begin(), m.end(), std::greater<std::pair<int, int>>());

    auto a = m[0]; // Initialize 'a' with the first tuple in the sorted list

    for (size_t i = 1; i < m.size(); ++i) {
        if (m[i].second > a.second) {
            std::cout << "Happy Alex" << std::endl;
            break;
        }
        a = m[i]; // Update 'a' to the current tuple
    }
    // If we have gone through all the tuples without finding one whose second element is greater
    else {
        std::cout << "Poor Alex" << std::endl;
    }

    return 0;
}
// <END-OF-CODE>
