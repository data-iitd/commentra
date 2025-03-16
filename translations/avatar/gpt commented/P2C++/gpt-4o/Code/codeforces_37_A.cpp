#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the number of elements from user input
    int n;
    std::cin >> n;

    // Read the list of integers from user input and store them in a vector
    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }

    // Initialize variables to track the height of the current tower and the total number of towers
    int high = 1;
    int tower = n;

    // Variable to keep track of the maximum height of any tower found
    int maximum = 1;

    // Sort the vector of integers to facilitate grouping of identical values
    std::sort(l.begin(), l.end());

    // Iterate through the sorted vector starting from the second element
    for (int i = 1; i < n; ++i) {
        // Check if the current element is the same as the previous one
        if (l[i] == l[i - 1]) {
            // If they are the same, increment the height of the current tower and decrease the tower count
            tower--;
            high++;
        } else {
            // If they are different, check if the current tower's height is greater than the maximum found so far
            if (high > maximum) {
                maximum = high;
            }
            // Reset the height for the new tower
            high = 1;
        }
    }

    // After the loop, check again if the last tower's height is greater than the maximum found
    if (high > maximum) {
        maximum = high;
    }

    // Print the maximum height of the towers and the total number of towers
    std::cout << maximum << " " << tower << std::endl;

    return 0;
}

// <END-OF-CODE>
