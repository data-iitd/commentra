#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the number of elements from standard input
    int n;
    std::cin >> n;

    // Initialize a vector to hold the float numbers
    std::vector<double> a(n);

    // Read n float numbers from standard input into the vector
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Perform a series of operations to reduce the vector
    for (int i = 0; i + 1 < n; i++) {
        // Sort the vector in ascending order
        std::sort(a.begin(), a.end());

        // Create a new vector to hold the modified values
        std::vector<double> na;

        // Append all elements from the third element onward to the new vector
        for (size_t j = 2; j < a.size(); j++) {
            na.push_back(a[j]);
        }

        // Calculate the average of the first two elements and append it to the new vector
        na.push_back((a[0] + a[1]) / 2);

        // Update the original vector to be the new vector
        a = na;
    }

    // Print the final remaining element in the vector
    std::cout << a[0] << std::endl;

    return 0;
}

// <END-OF-CODE>
