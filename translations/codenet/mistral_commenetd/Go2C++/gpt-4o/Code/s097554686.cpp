// Include necessary libraries
#include <iostream>
#include <vector>

using namespace std;

// Constants declaration with initializing size of the memory vector
const int size = 100001;

// Main function definition
int main() {
    // Variable declaration and initialization for number of queries and time interval
    int n, t;

    // Initializing memory vector with zero values
    vector<int> mem(size, 0);

    // Reading input values for number of queries and time interval
    cin >> n;
    cin >> t;

    // Iterating through each query in the input
    for (int i = 0; i < n; i++) {
        // Variable declaration for start and end time intervals
        int l, r;
        
        // Reading input values for start and end time intervals
        cin >> l;
        cin >> r;

        // Updating memory vector values for start and end time intervals
        mem[l] += 1;
        mem[r] -= 1;
    }

    // Initializing variable for answer
    int ans = mem[0];

    // Iterating through each time interval in the memory vector
    for (int i = 1; i <= t; i++) {
        // Updating memory vector values by adding previous value
        mem[i] += mem[i - 1];

        // Updating answer if current memory vector value is greater than previous answer
        if (ans < mem[i]) {
            ans = mem[i];
        }
    }

    // Printing the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
