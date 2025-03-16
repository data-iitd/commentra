#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;  // Read the number of elements in the list
    std::vector<int> l;  // Initialize a vector to store the elements

    // Read n elements and append them to the vector l
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        l.push_back(element);
    }

    int ans = n - 1;  // Initialize ans to n - 1, which will store the final answer
    int last = 0;  // Initialize last to 0, used to track the last element in the list

    // Iterate over each element in the vector l
    for (int i : l) {
        ans += std::abs(last - i) + 1;  // Update ans based on the current element and last element
        last = i;  // Update last to the current element
    }

    std::cout << ans << std::endl;  // Print the final answer

    return 0;
}

