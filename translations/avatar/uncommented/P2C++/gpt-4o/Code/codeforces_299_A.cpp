#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n; // Read the number of elements
    std::vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i]; // Read the elements into the vector
    }
    
    std::sort(a.begin(), a.end()); // Sort the vector
    
    // Check if any element is not divisible by the first element
    bool anyNotDivisible = false;
    for (int x : a) {
        if (x % a[0] != 0) {
            anyNotDivisible = true;
            break;
        }
    }
    
    // Print the result based on the condition
    std::cout << (anyNotDivisible ? -1 : a[0]) << std::endl;

    return 0;
}

// <END-OF-CODE>
