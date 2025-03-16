#include <iostream> // Including the necessary header for input and output
#include <vector>   // Including the vector header for dynamic array
using namespace std; // Using the standard namespace

int main() {
    // Reading an integer n from user input, which represents the number of elements
    int n;
    cin >> n;

    // Initializing a vector to store the indices of elements that are equal to 1
    vector<int> arr;

    // Looping through the input values to find indices of elements equal to 1
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value; // Read the input value
        // If the input value is 1, add the current index to the vector
        if (value == 1) {
            arr.push_back(i);
        }
    }

    // Checking if the vector of indices is empty
    if (arr.empty()) {
        // If the vector is empty, print 0
        cout << 0 << endl;
    } else {
        // If the vector is not empty, initialize a result variable to 1
        long long result = 1;

        // Calculate the product of the differences between consecutive indices
        for (size_t i = 1; i < arr.size(); i++) {
            result *= (arr[i] - arr[i - 1]);
        }

        // Print the final result
        cout << result << endl;
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
