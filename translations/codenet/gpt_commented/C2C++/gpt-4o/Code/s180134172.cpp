#include <iostream>
#include <vector>

int main() {
    // Declare variables
    int n, k, o = 0;

    // Read the number of elements (n) and the number of smallest elements to sum (k)
    std::cin >> n >> k;

    // Create a vector to store the elements
    std::vector<int> p(n);

    // Read n integers into the vector p
    for(int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    // Selection sort algorithm to sort the vector p in ascending order
    for(int i = 0; i < n; i++) {
        int l = i; // Assume the minimum is the first element
        for(int j = i + 1; j < n; j++) {
            // Update l if a smaller element is found
            if(p[j] < p[l]) {
                l = j;
            }
        }
        // Swap the found minimum element with the first element
        if(l != i) {
            std::swap(p[i], p[l]);
        }
    }

    // Calculate the sum of the first k smallest elements in the sorted vector
    for(int i = 0; i < k; i++) {
        o += p[i];
    }

    // Print the result: the sum of the k smallest elements
    std::cout << o << std::endl;

    return 0;
}

// <END-OF-CODE>
