#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Take an integer input from the user
    int y;
    cin >> y;

    // Take a list of integers as input from the user
    vector<int> arr(y);
    for (int i = 0; i < y; i++) {
        cin >> arr[i];
    }

    // Iterate through each index 'i' in the list 'arr'
    for (int i = 0; i < arr.size(); i++) {
        // Iterate through each index 'j' in the list 'arr' (excluding the current index 'i')
        for (int j = 0; j < arr.size(); j++) {
            // Check if the current indices 'i' and 'j' are equal, if yes then skip the current iteration
            if (i == j) {
                continue;
            }
            // Iterate through each index 'k' in the list 'arr' (excluding the indices 'i' and 'j')
            for (int k = 0; k < arr.size(); k++) {
                // Check if the current indices 'i', 'j' and 'k' satisfy the given condition
                if (arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j]) {
                    // If the condition is true, print the indices 'i', 'j' and 'k' and exit the function
                    cout << (k + 1) << " " << (j + 1) << " " << (i + 1) << endl;
                    return 0;
                }
            }
        }
    }
    // If no such indices are found, print -1
    cout << -1 << endl;

    return 0;
}
// <END-OF-CODE>
