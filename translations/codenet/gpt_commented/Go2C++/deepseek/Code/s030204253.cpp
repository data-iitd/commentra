#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate

int main() {
    // Read the number of elements from standard input
    int n;
    std::cin >> n;

    // Initialize a vector to hold the float64 numbers
    std::vector<double> a(n);

    // Read n float64 numbers from standard input into the vector
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Perform a series of operations to reduce the vector
    while (n > 1) {
        // Sort the vector in ascending order
        std::sort(a.begin(), a.end());

        // Create a new vector to hold the modified values
        std::vector<double> na;

        // Append all elements from the third element onward to the new vector
        for (int j = 2; j < n; j++) {
            na.push_back(a[j]);
        }

        // Calculate the average of the first two elements and append it to the new vector
        double avg = (a[0] + a[1]) / 2;
        na.push_back(avg);

        // Update the original vector to be the new vector
        a = na;
        n = a.size();
    }

    // Print the final remaining element in the vector
    std::cout << a[0] << std::endl;

    return 0;
}
