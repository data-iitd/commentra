#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, cnt = 0;
    std::cin >> n; // Read the number of elements in the array
    std::vector<int> l(n); // Create a vector to hold the elements

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        std::cin >> l[i];
    }

    // Sort the array in ascending order
    std::sort(l.begin(), l.end());

    // Count the number of valid triangles that can be formed
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (l[i] + l[j] > l[k]) {
                    cnt++;
                } else {
                    break; // No need to check further as the array is sorted
                }
            }
        }
    }

    // Print the count of valid triangles
    std::cout << cnt << std::endl;
    return 0;
}

// <END-OF-CODE>
