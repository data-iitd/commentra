
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read a line of input, split it into components, and convert each component to an integer
    std::vector<int> a(3);
    std::cin >> a[0] >> a[1] >> a[2];

    // Iterate over the vector 'a' using std::find to find the first occurrence of zero
    auto it = std::find(a.begin(), a.end(), 0);
    if (it!= a.end()) {
        // Print the index (0-based) of the first occurrence of zero
        std::cout << std::distance(a.begin(), it) + 1 << std::endl;
    }

    return 0;
}
