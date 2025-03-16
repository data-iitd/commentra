#include <iostream>
#include <vector>

int main() {
    // Read a list of space-separated integers from standard input
    std::vector<int> a;
    int num;
    
    // Read integers until end of input
    while (std::cin >> num) {
        a.push_back(num);
    }

    // Iterate over the elements of the vector a
    for (size_t index = 0; index < a.size(); ++index) {
        // Check if the current value is equal to zero
        if (a[index] == 0) {
            // Print the index of the first zero (1-based index)
            std::cout << index + 1 << std::endl;
            // Terminate the loop
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
