#include <iostream>
#include <vector>

int main() {
    // Take an integer input from the user
    int inp;
    std::cin >> inp;

    // Create a vector to store the input integers
    std::vector<int> lista(inp);

    // Populate the vector 'lista' with integers input by the user, separated by spaces
    for (int i = 0; i < inp; ++i) {
        std::cin >> lista[i];
    }

    // Iterate through each index 'i' in the vector 'lista'
    for (int i = 0; i < lista.size(); ++i) {
        // If 'i' is the first index
        if (i == 0) {
            // Print the difference between the second and first elements and the difference between the last and first elements
            std::cout << lista[i + 1] - lista[i] << " " << lista[lista.size() - 1] - lista[i] << std::endl;
            continue;
        }
        // If 'i' is the last index
        else if (i == lista.size() - 1) {
            // Print the difference between the last and second last element and the difference between the last and first element
            std::cout << lista[lista.size() - 1] - lista[lista.size() - 2] << " " << lista[lista.size() - 1] - lista[0] << std::endl;
            continue;
        }
        // If the difference between the current index and the previous index is greater than the difference between the next index and the current index
        else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            // Print the difference between the next index and the current index
            std::cout << lista[i + 1] - lista[i] << " ";
        }
        // If the difference between the current index and the previous index is less than or equal to the difference between the next index and the current index
        else {
            // Print the difference between the current index and the previous index and the difference between the current index and the first index
            std::cout << lista[i] - lista[i - 1] << " ";
            if (lista[lista.size() - 1] - lista[i] > lista[i] - lista[0]) {
                std::cout << lista[lista.size() - 1] - lista[i] << std::endl;
            } else {
                std::cout << lista[i] - lista[0] << std::endl;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
