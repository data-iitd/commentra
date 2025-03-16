#include <iostream>
#include <vector>

int main() {
    std::vector<int> a;
    int num;

    // Take input from user
    while (std::cin >> num) {
        a.push_back(num);
        if (std::cin.peek() == '\n') break; // Break on newline
    }

    // Iterate over the list, checking each element
    for (size_t e = 0; e < a.size(); ++e) {
        if (a[e] == 0) { // If an element is 0
            std::cout << e + 1 << std::endl; // Print the position (1-indexed) of that element and break the loop
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
