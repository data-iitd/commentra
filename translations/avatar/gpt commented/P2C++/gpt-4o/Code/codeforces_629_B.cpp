#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initialize a constant N for the size of the arrays
    const int N = 368;

    // Create two vectors to track the values for 'M' and 'F'
    vector<int> m(N, 0);  // Vector to track 'M' values
    vector<int> f(N, 0);  // Vector to track 'F' values

    // Read the number of operations from input
    int operations;
    cin >> operations;
    cin.ignore();  // Ignore the newline character after the integer input

    for (int i = 0; i < operations; ++i) {
        // Read the operation type and the indices a and b
        string x;
        int a, b;
        cin >> x >> a >> b;
        b += 1;  // Increment b by 1 for range adjustment

        // Update the corresponding vector based on the operation type
        if (x == "M") {
            m[a] += 2;  // Increment the value at index a in the 'M' vector
            m[b] -= 2;  // Decrement the value at index b in the 'M' vector
        } else {
            f[a] += 2;  // Increment the value at index a in the 'F' vector
            f[b] -= 2;  // Decrement the value at index b in the 'F' vector
        }
    }

    // Initialize variables to track cumulative sums and the minimum value
    int a_sum = 0, b_sum = 0, c = 0;

    // Iterate through the range of N to calculate cumulative sums and find the minimum
    for (int i = 0; i < N; ++i) {
        a_sum += m[i];  // Update cumulative sum for 'M'
        b_sum += f[i];  // Update cumulative sum for 'F'
        
        // Update the minimum value if the current minimum of a_sum and b_sum is greater than c
        if (min(a_sum, b_sum) > c) {
            c = min(a_sum, b_sum);  // Set c to the new minimum value
        }
    }

    // Print the final minimum value found
    cout << c << endl;

    return 0;
}

// <END-OF-CODE>
