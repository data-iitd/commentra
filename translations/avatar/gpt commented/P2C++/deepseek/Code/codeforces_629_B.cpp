#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initialize a constant N for the size of the arrays
    const int N = 368;

    // Create two vectors to track the values for 'M' and 'F'
    vector<int> m(N, 0);  // List to track 'M' values
    vector<int> f(N, 0);  // List to track 'F' values

    // Read the number of operations from input
    int num_operations;
    cin >> num_operations;
    cin.ignore();  // Ignore the newline character after the number of operations

    for (int i = 0; i < num_operations; ++i) {
        // Read the operation type and the indices a and b
        char x;
        int a, b;
        cin >> x >> a >> b;

        // Update the corresponding vector based on the operation type
        if (x == 'M') {
            m[a] += 2;  // Increment the value at index a in the 'M' list
            m[b] -= 2;  // Decrement the value at index b in the 'M' list
        } else {
            f[a] += 2;  // Increment the value at index a in the 'F' list
            f[b] -= 2;  // Decrement the value at index b in the 'F' list
        }
    }

    // Initialize variables to track cumulative sums and the minimum value
    int a = 0, b = 0, c = 0;

    // Iterate through the range of N to calculate cumulative sums and find the minimum
    for (int i = 0; i < N; ++i) {
        a += m[i];  // Update cumulative sum for 'M'
        b += f[i];  // Update cumulative sum for 'F'

        // Update the minimum value if the current minimum of a and b is greater than c
        if (min(a, b) > c) {
            c = min(a, b);  // Set c to the new minimum value
        }
    }

    // Print the final minimum value found
    cout << c << endl;

    return 0;
}
