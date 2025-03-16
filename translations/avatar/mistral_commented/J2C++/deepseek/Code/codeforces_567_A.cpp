#include <iostream>
#include <vector>
#include <algorithm> // for std::max and std::min

int main() {
    int a;
    std::cin >> a;
    std::vector<int> ar(a);

    // Reading array elements from user input
    for (int i = 0; i < ar.size(); i++) {
        std::cin >> ar[i];
    }

    // Initializing variables for storing maximum and minimum differences
    int max = 0, min = 0;

    // Finding maximum and minimum differences between consecutive elements in the array
    for (int i = 0; i < ar.size(); i++) {
        // Finding maximum difference between current element and first element
        max = std::max(ar[i] - ar[0], ar[ar.size() - 1] - ar[i]);

        // Finding minimum difference between current element and previous element
        if (i == 0) {
            min = ar[i + 1] - ar[i]; // For the first element, minimum difference is between current and next element
        } else if (i == ar.size() - 1) {
            min = ar[i] - ar[i - 1]; // For the last element, minimum difference is between current and previous element
        } else {
            min = std::min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]); // For other elements, minimum difference is between current and previous or next element, whichever is smaller
        }

        // Printing minimum and maximum differences for each pair of consecutive elements
        std::cout << min << " " << max << std::endl;
    }

    return 0;
}
