#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    // Initialize input stream
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Read the number of elements
    int n;
    std::cin >> n;

    // Create a vector to hold the float values
    std::vector<double> arr(n);

    // Read n integers from input and convert them to double
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        arr[i] = static_cast<double>(temp);
    }

    // Sort the array of double values
    std::sort(arr.begin(), arr.end());

    // Initialize 'prev' with the first element of the sorted array
    double prev = arr[0];

    // Calculate the average of the elements iteratively
    for (size_t i = 1; i < arr.size(); i++) {
        prev = (prev + arr[i]) / 2;
    }

    // Print the final computed average
    std::cout << prev << "\n";

    return 0;
}

// <END-OF-CODE>
