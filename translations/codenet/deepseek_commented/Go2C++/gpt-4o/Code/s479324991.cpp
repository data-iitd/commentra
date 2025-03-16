#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    // Initialize a vector to hold the float values
    std::vector<double> arr(n);

    // Read each integer and convert it to double, then store in the vector
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        arr[i] = static_cast<double>(temp);
    }

    // Sort the vector of double values
    std::sort(arr.begin(), arr.end());

    // Initialize a variable to keep track of the running average
    double prev = arr[0];

    // Iterate through the sorted vector to calculate the average
    for (size_t i = 1; i < arr.size(); i++) {
        prev = (prev + arr[i]) / 2;
    }

    // Print the final average
    std::cout << std::fixed << std::setprecision(6) << prev << std::endl;

    return 0;
}

// <END-OF-CODE>
