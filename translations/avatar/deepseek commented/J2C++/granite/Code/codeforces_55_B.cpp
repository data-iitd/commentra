
#include <iostream> // Including the necessary libraries
#include <vector>
#include <algorithm>

using namespace std;

long long min; // Declaring a static variable to keep track of the minimum result

void util(vector<long long> arr, vector<string> ops, int idx) {
    if (idx == 3) { // Base case: when all operations are applied
        min = min(min, arr[0]); // Update min with the current result
        return;
    }

    // Iterating through the array to apply operations between two numbers
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            vector<long long> a; // Temporary vector to store remaining numbers
            for (int k = 0; k < arr.size(); k++) {
                if (k!= j && k!= i) {
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
    vector<long long> arr; // Creating a vector to store the numbers
    for (int i = 0; i < 4; i++) {
        long long num; // Variable to store the input number
        cin >> num; // Reading the input number
        arr.push_back(num); // Adding the number to the vector
    }

    vector<string> ops; // Creating a vector to store the operations
    for (int i = 0; i < 3; i++) {
        string op; // Variable to store the input operation
        cin >> op; // Reading the input operation
        ops.push_back(op); // Adding the operation to the vector
    }

    min = LLONG_MAX; // Initializing min to the maximum possible long long value
    util(arr, ops, 0); // Calling the util function to find the minimum result

    // Outputting the minimum result
    cout << min << endl; // Outputting the minimum result

    return 0; // Ending the program
}

