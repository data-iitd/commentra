#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;  // Take an integer input representing the number of elements
    std::vector<int> list(n);
    
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;  // Read each element
        list[i] = x % 2;  // Calculate remainders modulo 2
    }

    // Check if the sum of the list is 1
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += list[i];
    }

    if (sum == 1) {
        for (int i = 0; i < n; ++i) {
            if (list[i] == 1) {
                std::cout << i + 1 << std::endl;  // Print the index of the first occurrence of 1 (adjusted for 1-based indexing)
                break;
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (list[i] == 0) {
                std::cout << i + 1 << std::endl;  // Print the index of the first occurrence of 0 (adjusted for 1-based indexing)
                break;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
