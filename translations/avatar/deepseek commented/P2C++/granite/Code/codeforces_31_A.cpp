

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int y;
    cin >> y;  // Take an integer input for variable y
    vector<int> arr(y);  // Take a list of integers as input and store it in arr
    for (int i = 0; i < y; i++) {
        cin >> arr[i];
    }

    // Iterate through the list arr using three nested loops
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < y; j++) {
            if (i == j) {
                continue;  // Skip if i and j are the same index
            }
            for (int k = 0; k < y; k++) {
                if (arr[k]!= arr[j] && arr[k]!= arr[i] && arr[k] == arr[i] + arr[j]) {
                    // Check if arr[k] is the sum of arr[i] and arr[j] and different from both
                    cout << k + 1 << " " << j + 1 << " " << i + 1 << endl;  // Print the positions of arr[k], arr[j], and arr[i] (1-indexed)
                    return 0;  // Exit the program
                }
            }
        }
    }
    cout << -1 << endl;  // Print -1 if no such element is found
    return 0;
}
