#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

long long minResult; // Declaring a variable to keep track of the minimum result

void util(vector<long long>& arr, string ops[], int idx) {
    if (idx == 3) { // Base case: when all operations are applied
        minResult = min(minResult, arr[0]); // Update min with the current result
        return;
    }

    // Iterating through the array to apply operations between two numbers
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            vector<long long> a; // Temporary vector to store remaining numbers
            for (size_t k = 0; k < arr.size(); k++) {
                if (k != j && k != i) {
                    a.push_back(arr[k]); // Adding remaining numbers to the temporary vector
                }
            }

            long long res; // Variable to store the result of the operation
            if (idx < 3 && ops[idx] == "+") {
                res = arr[i] + arr[j]; // Applying addition
            } else {
                res = arr[i] * arr[j]; // Applying multiplication
            }

            a.push_back(res); // Adding the result to the temporary vector
            util(a, ops, idx + 1); // Recursively calling util with the updated vector and index
        }
    }
}

int main() {
    minResult = LLONG_MAX; // Initializing minResult to the maximum possible long long value
    vector<long long> arr(4); // Creating a vector to store the numbers

    // Reading four numbers and adding them to the vector
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    // Reading three operations and storing them in an array
    string ops[3];
    for (int i = 0; i < 3; i++) {
        cin >> ops[i];
    }

    // Calling the recursive function to find the minimum result
    util(arr, ops, 0);

    // Outputting the minimum result
    cout << minResult << endl;

    return 0;
}

// <END-OF-CODE>
