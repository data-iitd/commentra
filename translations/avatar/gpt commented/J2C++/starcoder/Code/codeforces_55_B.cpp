#include <bits/stdc++.h>
using namespace std;

// Variable to store the minimum result found
long long min;

// Recursive utility function to perform operations and find the minimum result
void util(vector<long long> arr, string ops[], int idx) {
    // Base case: if all operations have been used, update the minimum result
    if (idx == 3) {
        min = min < arr[0]? min : arr[0];
        return;
    }

    // Iterate through all pairs of numbers in the list
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            // Create a new list to hold the remaining numbers after the operation
            vector<long long> a;

            // Add the remaining numbers to the new list
            for (int k = 0; k < arr.size(); k++) {
                if (k!= j && k!= i) {
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

            // Add the result of the operation to the new list
            a.push_back(res);

            // Recursively call util with the new list and the next operation index
            util(a, ops, idx + 1);
        }
    }
}

int main() {
    // Create a Scanner object for user input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    Scanner sc;

    // Initialize min to the maximum possible value
    min = LLONG_MAX;

    // Create an vector to store the input numbers
    vector<long long> arr;

    // Read 4 long integers from user input and add them to the list
    for (int i = 0; i < 4; i++) {
        long long x;
        cin >> x;
        arr.push_back(x);
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
    cout << min << "\n";

    return 0;
}

