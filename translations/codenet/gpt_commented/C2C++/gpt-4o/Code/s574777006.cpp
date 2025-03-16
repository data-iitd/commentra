#include <iostream>
#include <vector>

int main() {
    // Declare variables
    int n, q, sum = 0;
    std::vector<int> x(10000), y(500);
    
    // Read the number of elements in array x
    std::cin >> n;
    
    // Read n elements into array x
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    
    // Read the number of queries
    std::cin >> q;
    
    // Read q elements into array y
    for (int i = 0; i < q; i++) {
        std::cin >> y[i];
    }
    
    // Initialize sum to count how many elements in y are found in x
    for (int i = 0; i < q; i++) {
        // Check each element in y against all elements in x
        for (int j = 0; j < n; j++) {
            // If a match is found, increment sum and break the inner loop
            if (y[i] == x[j]) {
                sum++;
                break;
            }
        }
    }
    
    // Output the total count of matches found
    std::cout << sum << std::endl;
    
    return 0;
}

// <END-OF-CODE>
