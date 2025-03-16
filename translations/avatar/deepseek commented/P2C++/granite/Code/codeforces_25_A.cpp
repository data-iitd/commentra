

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;  // Take an integer input representing the number of elements
    std::vector<int> list(n);  // Create a vector to store the elements
    for (int i = 0; i < n; i++) {
        std::cin >> list[i];  // Read the elements from the input
        list[i] %= 2;  // Calculate the remainder modulo 2
    }

    // Check if the sum of the list is 1
    if (std::accumulate(list.begin(), list.end(), 0) == 1) {
        int index = std::distance(list.begin(), std::find(list.begin(), list.end(), 1));  // Find the index of the first occurrence of 1
        std::cout << index + 1 << std::endl;  // Print the index of the first occurrence of 1 (adjusted for 1-based indexing)
    } else {
        int index = std::distance(list.begin(), std::find(list.begin(), list.end(), 0));  // Find the index of the first occurrence of 0
        std::cout << index + 1 << std::endl;  // Print the index of the first occurrence of 0 (adjusted for 1-based indexing)
    }

    return 0;
}

