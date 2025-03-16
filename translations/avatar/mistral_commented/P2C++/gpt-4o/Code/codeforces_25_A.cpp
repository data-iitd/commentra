#include <iostream>
#include <vector>

int main() {
    // Read user input and assign it to the variable 'n'
    int n;
    std::cin >> n;

    // Create a vector 'list' with the same length as 'n'
    // Each element in the vector is the remainder of the corresponding input value divided by 2
    std::vector<int> list(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        list[i] = x % 2;
    }

    // Check if the sum of all elements in the list is equal to 1
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += list[i];
    }

    if (sum == 1) {
        // If the condition is true, print the index of the first occurrence of the number 1 in the list
        for (int i = 0; i < n; ++i) {
            if (list[i] == 1) {
                std::cout << "The first number with remainder 1 is: " << (i + 1) << std::endl;
                break;
            }
        }
    } else {
        // If the condition is false, print the index of the first occurrence of the number 0 in the list
        for (int i = 0; i < n; ++i) {
            if (list[i] == 0) {
                std::cout << "The first number with remainder 0 is: " << (i + 1) << std::endl;
                break;
            }
        }
    }

    return 0;
}
// <END-OF-CODE>
