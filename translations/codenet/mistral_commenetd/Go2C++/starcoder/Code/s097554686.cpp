
// C++ code by <NAME>

#include <bits/stdc++.h>

using namespace std;

// Constants declaration with initializing size of the memory slice
const int size = 100001;

// Function definition for main function
int main() {
    // Variable declaration and initialization for number of queries and time interval
    int n, t;

    // Initializing memory slice with zero values
    int mem[size] = {0};

    // Reading input values for number of queries and time interval
    cin >> n;
    cin >> t;

    // Iterating through each query in the input
    for (int i = 0; i < n; i++) {
        // Reading input values for start and end time intervals
        int l, r;
        cin >> l;
        cin >> r;

        // Updating memory slice values for start and end time intervals
        mem[l] += 1;
        mem[r] -= 1;
    }

    // Initializing variable for answer
    int ans = mem[0];

    // Iterating through each time interval in the memory slice
    for (int i = 1; i < t + 1; i++) {
        // Updating memory slice values by adding previous value
        mem[i] += mem[i - 1];

        // Updating answer if current memory slice value is greater than previous answer
        if (ans < mem[i]) {
            ans = mem[i];
        }
    }

    // Printing the final answer
    cout << ans << endl;

    // End of code
    return 0;
}

