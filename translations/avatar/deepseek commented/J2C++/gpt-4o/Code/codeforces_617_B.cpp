#include <iostream>
#include <vector>

using namespace std;

int main() { // Step 4: Define the main method.
    int n;
    cin >> n; // Step 5: Read the number of elements.
    vector<int> arr; // Step 6: Create a vector to store the indices of elements equal to 1.

    for (int i = 0; i < n; i++) { // Step 7: Read the elements and store their indices if they are equal to 1.
        int value;
        cin >> value;
        if (value == 1) {
            arr.push_back(i);
        }
    }

    if (arr.empty()) { // Step 8: Check if the vector is empty.
        cout << 0 << endl; // If the vector is empty, print 0.
    } else {
        long long result = 1; // Initialize the result variable to 1.
        for (size_t i = 1; i < arr.size(); i++) { // Step 9: Calculate the product of differences between consecutive indices.
            result *= arr[i] - arr[i - 1];
        }
        cout << result << endl; // Print the result.
    }

    return 0; // End of the main function.
}

// <END-OF-CODE>
