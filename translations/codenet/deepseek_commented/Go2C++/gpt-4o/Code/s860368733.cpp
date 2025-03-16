#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n, m; // Declare variables to store the number of elements and comparisons
    std::cin >> n >> m; // Read the number of elements and comparisons from standard input
    std::vector<int> h(n); // Create a vector to store the heights of the elements
    for (int i = 0; i < n; i++) {
        std::cin >> h[i]; // Read the heights of the elements from standard input
    }
    
    int a, b; // Declare variables to store the indices of the elements being compared
    std::unordered_set<int> counter; // Create a set to keep track of elements that cannot be the highest
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b; // Read each comparison from standard input
        if (h[a - 1] < h[b - 1]) { // Check if the height of the first element is less than the second
            counter.insert(a); // Mark the first element as not being the highest
        } else if (h[a - 1] > h[b - 1]) { // Check if the height of the first element is greater than the second
            counter.insert(b); // Mark the second element as not being the highest
        } else { // Check if the heights of the two elements are equal
            counter.insert(a); // Mark both elements as not being the highest
            counter.insert(b);
        }
    }
    
    std::cout << n - counter.size() << std::endl; // Print the number of elements that cannot be the highest
    return 0;
}

// <END-OF-CODE>
