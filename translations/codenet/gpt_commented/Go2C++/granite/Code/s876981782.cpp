
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the number of values to be processed
    int N;
    std::cin >> N;

    // Initialize a vector to hold the float64 values
    std::vector<double> values(N);

    // Read N float64 values from standard input
    for (int i = 0; i < N; i++) {
        std::cin >> values[i];
    }

    // Sort the vector of float64 values in ascending order
    std::sort(values.begin(), values.end());

    // Variable to hold the generated average value
    double generated;

    // Calculate the average of each pair of adjacent values
    for (int i = 0; i < N - 1; i++) {
        generated = (values[i] + values[i + 1]) / 2;
        // Update the next value in the vector with the generated average
        values[i + 1] = generated;
    }

    // Print the last generated average value
    std::cout << generated << std::endl;

    return 0;
}
