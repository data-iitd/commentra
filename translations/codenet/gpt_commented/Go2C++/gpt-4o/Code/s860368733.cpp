#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    // Declare variables for the number of elements (n) and the number of comparisons (m)
    int n, m;
    
    // Read the values of n and m from standard input
    std::cin >> n >> m;
    
    // Create a vector to hold the heights of n elements
    std::vector<int> h(n);
    
    // Read the heights of the n elements from standard input
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    
    // Declare variables for the two elements to compare (a and b)
    int a, b;
    
    // Create a set to keep track of unique elements that are involved in comparisons
    std::unordered_set<int> counter;
    
    // Loop through m comparisons
    for (int i = 0; i < m; i++) {
        // Read the indices of the two elements to compare
        std::cin >> a >> b;
        
        // Compare the heights of the two elements
        if (h[a - 1] < h[b - 1]) {
            // If height of a is less than height of b, add a to the counter
            counter.insert(a);
        } else if (h[a - 1] > h[b - 1]) {
            // If height of a is greater than height of b, add b to the counter
            counter.insert(b);
        } else {
            // If heights are equal, add both a and b to the counter
            counter.insert(a);
            counter.insert(b);
        }
    }
    
    // Print the number of elements that were not involved in any comparisons
    std::cout << n - counter.size() << std::endl;

    return 0;
}
// <END-OF-CODE>
