#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Variable to store the minimum result found
long long minResult;

void util(vector<long long>& arr, string ops[], int idx) {
    // Base case: if all operations have been used, update the minimum result
    if (idx == 3) {
        minResult = min(minResult, arr[0]);
        return;
    }

    // Iterate through all pairs of numbers in the list
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            // Create a new vector to hold the remaining numbers after the operation
            vector<long long> a;

            // Add the remaining numbers to the new vector
            for (size_t k = 0; k < arr.size(); k++) {
                if (k != j && k != i) {
                    a.push_back(arr[k]);
                }
            }

            long long res;
            // Perform the operation based on the current operation in the ops array
            if (idx < 3 && ops[idx] == "+") {
                res = arr[i] + arr[j]; // Addition operation
            } else {
                res = arr[i] * arr[j]; // Multiplication operation
            }

            // Add the result of the operation to the new vector
            a.push_back(res);

            // Recursively call util with the new vector and the next operation index
            util(a, ops, idx + 1);
        }
    }
}

int main() {
    // Initialize minResult to the maximum possible value
    minResult = numeric_limits<long long>::max();

    // Create a vector to store the input numbers
    vector<long long> arr(4);

    // Read 4 long integers from user input and add them to the vector
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    // Create an array to store the operations
    string ops[3];

    // Read 3 operations from user input
    for (int i = 0; i < 3; i++) {
        cin >> ops[i];
    }

    // Call the utility function to compute the minimum result
    util(arr, ops, 0);

    // Print the minimum result found
    cout << minResult << endl;

    return 0;
}

// <END-OF-CODE>
