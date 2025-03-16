#include <iostream>
#include <vector>

int main() {
    // Read an integer input which represents the number of elements
    int n;
    std::cin >> n;

    // Create a vector to store 1 for odd numbers and 0 for even numbers
    std::vector<int> list(n);
    
    // Read the elements and populate the list
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        list[i] = x % 2; // 1 for odd, 0 for even
    }

    // Check if there is exactly one odd number in the list
    int oddCount = 0;
    int oddIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (list[i] == 1) {
            oddCount++;
            oddIndex = i; // Store the index of the odd number
        }
    }

    if (oddCount == 1) {
        // If there is one odd number, print its position (1-based index)
        std::cout << oddIndex + 1 << std::endl;
    } else {
        // If there are no odd numbers, print the position of the first even number (1-based index)
        for (int i = 0; i < n; ++i) {
            if (list[i] == 0) {
                std::cout << i + 1 << std::endl;
                break;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
