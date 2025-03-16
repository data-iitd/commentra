#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;  // Read the number of elements
    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];  // Read the list of elements
    }

    // Initialize variables
    int high = 1;
    int tower = n;
    int maximum = 1;

    // Sort the list
    std::sort(l.begin(), l.end());

    // Loop through the sorted list
    for (int i = 1; i < n; ++i) {
        if (l[i] == l[i - 1]) {  // Check if the current element is equal to the previous element
            tower -= 1;  // Decrement the tower count
            high += 1;  // Increment the high count
        } else {
            if (high > maximum) {  // Check if the current high is greater than the maximum
                maximum = high;  // Update the maximum
            }
            high = 1;  // Reset high to 1
        }
    }

    if (high > maximum) {  // Check if the final high is greater than the maximum
        maximum = high;  // Update the maximum
    }

    // Print the result
    std::cout << maximum << " " << tower << std::endl;

    return 0;
}
