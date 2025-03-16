#include <iostream>
#include <vector>

int main() {
    int inp;
    std::cin >> inp;  // Taking an integer input from the user
    std::vector<int> lista(inp);  // Creating a vector to hold the integers

    // Converting the input string into a vector of integers
    for (int i = 0; i < inp; ++i) {
        std::cin >> lista[i];
    }

    // Iterating through the vector of integers
    for (int i = 0; i < lista.size(); ++i) {
        // For the first element in the list
        if (i == 0) {
            std::cout << lista[i + 1] - lista[i] << " " << lista[lista.size() - 1] - lista[i] << std::endl;  // Printing the differences
            continue;
        }
        // For the last element in the list
        else if (i == lista.size() - 1) {
            std::cout << lista[lista.size() - 1] - lista[lista.size() - 2] << " " << lista[lista.size() - 1] - lista[0] << std::endl;  // Printing the differences
            continue;
        }
        // For other elements in the list
        else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            std::cout << lista[i + 1] - lista[i] << " ";  // Printing the difference between the next and current integer
        } else {
            std::cout << lista[i] - lista[i - 1] << " ";  // Printing the difference between the current and previous integer
        }
        // Printing the difference between the last and current integer or the first and current integer
        if (lista[lista.size() - 1] - lista[i] > lista[i] - lista[0]) {
            std::cout << lista[lista.size() - 1] - lista[i] << std::endl;  // Printing the difference between the last and current integer
        } else {
            std::cout << lista[i] - lista[0] << std::endl;  // Printing the difference between the first and current integer
        }
    }

    return 0;
}

// <END-OF-CODE>
