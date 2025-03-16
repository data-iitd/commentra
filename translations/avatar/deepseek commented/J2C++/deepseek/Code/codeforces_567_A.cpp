#include <iostream>
#include <vector>
#include <algorithm> // for std::max and std::min

int main() {
    int a;
    std::cin >> a;
    std::vector<int> ar(a);
    int max = 0, min = 0;

    // Filling the vector with integers read from the user
    for (int i = 0; i < ar.size(); i++) {
        std::cin >> ar[i];
    }

    // Calculating the minimum and maximum differences between consecutive elements of the vector
    for (int i = 0; i < ar.size(); i++) {
        max = std::max(ar[i] - ar[0], ar[ar.size() - 1] - ar[i]); // Calculating the maximum difference
        if (i == 0) {
            min = ar[i + 1] - ar[i]; // Calculating the minimum difference for the first element
        } else if (i == ar.size() - 1) {
            min = ar[i] - ar[i - 1]; // Calculating the minimum difference for the last element
        } else {
            min = std::min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]); // Calculating the minimum difference for other elements
        }
        std::cout << min << " " << max << std::endl; // Displaying the minimum and maximum differences
    }

    return 0;
}
