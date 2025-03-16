

#include <iostream>
#include <vector>

int main() {
    // Create a vector to store the input elements
    std::vector<int> elements;

    // Read the number of elements
    int n;
    std::cin >> n;

    // Read the elements and store them in the vector
    for (int i = 0; i < n; i++) {
        int element;
        std::cin >> element;
        elements.push_back(element);
    }

    // Calculate the sums of subsets
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        a += elements[i];
    }
    for (int i = 0; i < n - 1; i++) {
        b += elements[i];
    }
    for (int i = 0; i < n - 2; i++) {
        c += elements[i];
    }

    // Calculate the differences
    int x = a - b;
    int y = b - c;

    // Output the results
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    return 0;
}
