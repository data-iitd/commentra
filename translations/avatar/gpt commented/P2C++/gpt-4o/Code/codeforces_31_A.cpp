#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read an integer input which represents the size of the array
    int y;
    cin >> y;

    // Read the elements of the array
    vector<int> arr(y);
    for (int i = 0; i < y; ++i) {
        cin >> arr[i];
    }

    // Iterate over each element in the array using index i
    for (int i = 0; i < y; ++i) {
        // Iterate over each element in the array using index j
        for (int j = 0; j < y; ++j) {
            // Skip the iteration if both indices are the same
            if (i == j) {
                continue;
            }
            // Iterate over each element in the array using index k
            for (int k = 0; k < y; ++k) {
                // Check if the current element at index k is different from elements at indices i and j,
                // and if it is equal to the sum of the elements at indices i and j
                if (arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j]) {
                    // Print the 1-based indices of the elements that satisfy the condition
                    cout << (k + 1) << " " << (j + 1) << " " << (i + 1) << endl;
                    // Exit the program after finding the first valid triplet
                    return 0;
                }
            }
        }
    }

    // If no valid triplet is found, print -1
    cout << -1 << endl;

    return 0;
}

// <END-OF-CODE>
