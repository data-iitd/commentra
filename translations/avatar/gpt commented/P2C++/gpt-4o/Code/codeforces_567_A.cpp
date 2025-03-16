#include <iostream>
#include <vector>

int main() {
    // Read an integer input (not used later in the code)
    int inp;
    std::cin >> inp;

    // Initialize an empty vector to store integers
    std::vector<int> lista;

    // Read a line of input, split it into integers, and store it in lista
    int num;
    while (std::cin >> num) {
        lista.push_back(num);
        if (std::cin.peek() == '\n') break; // Stop reading on newline
    }

    // Iterate through the indices of the lista
    for (size_t i = 0; i < lista.size(); i++) {
        // Handle the first element in the list
        if (i == 0) {
            // Calculate and print the difference between the second and first elements,
            // and the difference between the last and first elements
            std::cout << lista[i + 1] - lista[i] << " " << lista[lista.size() - 1] - lista[i] << std::endl;
            continue;  // Skip to the next iteration
        }

        // Handle the last element in the list
        else if (i == lista.size() - 1) {
            // Calculate and print the difference between the last and second-to-last elements,
            // and the difference between the last and the first elements
            std::cout << lista[lista.size() - 1] - lista[lista.size() - 2] << " " << lista[lista.size() - 1] - lista[0] << std::endl;
            continue;  // Skip to the next iteration
        }

        // For elements in the middle of the list
        else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            // If the difference to the next element is smaller, print that difference
            std::cout << lista[i + 1] - lista[i] << " ";
        } else {
            // Otherwise, print the difference to the previous element
            std::cout << lista[i] - lista[i - 1] << " ";
        }

        // Compare the difference to the last element with the difference to the first element
        if (lista[lista.size() - 1] - lista[i] > lista[i] - lista[0]) {
            // If the difference to the last element is larger, print that difference
            std::cout << lista[lista.size() - 1] - lista[i] << std::endl;
        } else {
            // Otherwise, print the difference to the first element
            std::cout << lista[i] - lista[0] << std::endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
