#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    // Read the number of elements in the array
    int n;
    std::cin >> n;

    // Allocate memory for the array of size n
    std::vector<double> arr(n);

    // Read n integers from the standard input and store them in the array
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        arr[i] = static_cast<double>(temp);
    }

    // Sort the array in ascending order
    std::sort(arr.begin(), arr.end());

    // Initialize a variable prev to store the previous element in the sorted array
    double prev = arr[0];

    // Iterate through the sorted array from the second element to the last
    for (int i = 1; i < arr.size(); i++) {
        // Calculate the average of the previous and current elements
        prev = (prev + arr[i]) / 2;
    }

    // Print the result to the standard output
    std::cout << std::fixed << std::setprecision(6) << prev << std::endl;

    return 0;
}

// <END-OF-CODE>
