#include <iostream>
#include <vector>
#include <sstream>

int main() {
    // Initialize an empty vector `L`
    std::vector<int> L;

    // Read the first input, which is the number of elements to add to the list
    int n;
    std::cin >> n;

    // Initialize r
    int r = 1;

    // Use a for loop to iterate through each integer in the input
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        // Add `r` elements to the list `L` with the value `r`
        for (int j = 0; j < k; ++j) {
            L.push_back(r);
        }
        // Increment the value of `r` by 1 to prepare for the next iteration
        r++;
    }

    // Read the second input, which represents the indices of the elements to print from the list
    int m;
    std::cin >> m;

    // Use another for loop to iterate through each integer in the input
    for (int i = 0; i < m; ++i) {
        int j;
        std::cin >> j;
        // Print the element at the given index using the index as an offset from the beginning of the list
        std::cout << L[j - 1] << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
