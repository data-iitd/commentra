#include <iostream>
#include <vector>
#include <cstring> // for memset
using namespace std;

// Function prototype for max function
int max(int a, int b);

int main() {
    // Declare variables for input and results
    int n, k, t, ret = 0;

    // Infinite loop to continuously read input until termination condition
    while (true) {
        // Read values for n and k
        cin >> n >> k;

        // Break the loop if both n and k are zero
        if (n == 0 && k == 0) break;

        // Initialize data and seq vectors to hold counts
        vector<int> data(111112, 0); // size is 111112 to accommodate 0 to 111111
        vector<int> seq(222224, 0);  // size is 222224 to accommodate sequences

        // Read k integers and count their occurrences in the data array
        for (int i = 0; i < k; i++) {
            cin >> t;
            data[t]++;
        }

        // Initialize pointer for the sequence array
        int p = 0;

        // Build the seq array based on the data array
        for (int i = 1; i <= n; i++) {
            // If the current index has data, increment the sequence count
            if (data[i]) {
                seq[p]++;
            } else {
                // If no data, move the pointer by 2
                p += 2;
            }
        }
        // Increment pointer to account for the last sequence
        p++;

        // Calculate the maximum sequence length based on the presence of data[0]
        if (data[0]) {
            // If data[0] exists, consider sequences with gaps
            for (int i = 0; i < p; i++) {
                ret = max(ret, seq[i] + seq[i + 2] + 1);
            }
        } else {
            // If data[0] does not exist, consider sequences without gaps
            for (int i = 0; i < p; i++) {
                ret = max(ret, seq[i]);
            }
        }

        // Print the maximum sequence length found
        cout << ret << endl;
    }

    return 0;
}

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// <END-OF-CODE>
