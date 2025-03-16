#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Global arrays to hold data and sequence counts
int data[111111];
int seq[222222];

// Function prototype for max function
int max(int a, int b);

int main(void)
{
    // Declare variables for input and results
    int n, k, t, i, p, ret = 0;

    // Infinite loop to continuously read input until termination condition
    while(true) {
        // Read values for n and k
        cin >> n >> k;
        
        // Break the loop if both n and k are zero
        if (n == 0 && k == 0) break;

        // Initialize data and seq arrays to zero
        memset(data, 0, sizeof(data));
        memset(seq, 0, sizeof(seq));

        // Read k integers and count their occurrences in the data array
        for (i = 0; i < k; i++) {
            cin >> t;
            data[t]++;
        }

        // Initialize pointer for the sequence array
        p = 0;

        // Build the seq array based on the data array
        for (i = 1; i <= n; i++) {
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
            for (i = 0; i < p; i++) {
                ret = max(ret, seq[i] + seq[i + 2] + 1);
            }
        } else {
            // If data[0] does not exist, consider sequences without gaps
            for (i = 0; i < p; i++) {
                ret = max(ret, seq[i]);
            }
        }

        // Print the maximum sequence length found
        cout << ret << endl;
    }

    return 0;
}

// Function to return the maximum of two integers
int max(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

