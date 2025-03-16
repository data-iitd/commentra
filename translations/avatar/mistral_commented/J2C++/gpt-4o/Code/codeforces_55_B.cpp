#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library to use dynamic arrays
#include <limits>   // Including limits to use numeric limits
#include <string>   // Including string library for string operations

using namespace std; // Using the standard namespace

long long minValue; // Initializing the minimum value to a large number

void util(vector<long long>& arr, string ops[], int idx) { // Starting the util function
    if (idx == 3) { // Checking if the index of the operator is equal to 3 (the last operator)
        minValue = min(minValue, arr[0]); // Updating the minimum value with the first number in the vector
        return; // Exiting the function
    }

    for (int i = 0; i < arr.size(); i++) { // Iterating through the vector to find two numbers for the current operator
        for (int j = i + 1; j < arr.size(); j++) {
            vector<long long> a; // Creating a new vector to store the result of the current operation

            for (int k = 0; k < arr.size(); k++) { // Iterating through the vector to exclude the current and previous numbers
                if (k != j && k != i) {
                    a.push_back(arr[k]); // Adding the excluded number to the new vector
                }
            }

            long long res; // Initializing the result variable

            if (idx < 3 && ops[idx] == "+") { // Checking if the current operator is '+'
                res = arr[i] + arr[j]; // Performing the addition operation
            } else { // Else, the current operator is '*'
                res = arr[i] * arr[j]; // Performing the multiplication operation
            }

            a.push_back(res); // Adding the result to the new vector
            util(a, ops, idx + 1); // Recursively calling the util function with the new vector, the array of operators, and the index of the next operator
        }
    }
}

int main() { // Starting the main function
    cin >> std::numeric_limits<long long>::max(); // Setting the initial value of minValue to a large number
    minValue = std::numeric_limits<long long>::max(); // Setting the initial value of minValue to Long.MAX_VALUE
    vector<long long> arr(4); // Creating a vector of Long type to store the input numbers

    for (int i = 0; i < 4; i++) { // Reading 4 numbers from the standard input and storing them in the vector
        cin >> arr[i];
    }

    string ops[3]; // Creating an array of String type to store the operators

    for (int i = 0; i < 3; i++) { // Reading 3 operators from the standard input and storing them in the array
        cin >> ops[i];
    }

    util(arr, ops, 0); // Calling the util function with the vector, the array of operators, and the index of the first operator

    cout << minValue << endl; // Printing the minimum value found during the execution
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
