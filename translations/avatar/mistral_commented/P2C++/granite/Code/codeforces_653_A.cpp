

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;  // Read the number of elements in the list
    std::vector<int> l(n);  // Create a vector to store the list of integers
    for (int i = 0; i < n; i++) {
        std::cin >> l[i];  // Read the list of integers and store them in the vector
    }
    std::sort(l.begin(), l.end());  // Sort the vector in ascending order

    for (int i = 0; i < n - 2; i++) {  // Iterate through each element in the sorted vector
        if (std::binary_search(l.begin(), l.end(), l[i] + 1) && std::binary_search(l.begin(), l.end(), l[i] + 2)) {  // Check if the next two elements are also in the vector
            std::cout << "YES" << std::endl;  // If yes, print 'YES' and break out of the loop
            return 0;
        }
    }
    std::cout << "NO" << std::endl;  // If no, print 'NO' after the loop finishes

    return 0;
}

