// Include necessary header files
#include <iostream>
#include <vector>

using namespace std;

// Main function is the entry point of the C++ application
int main() {
    // Initialize variables to read the number of requests and preemptions
    int n, m;
    cin >> n >> m;

    // Create vectors to store request and preemption indices
    vector<int> req(n);
    vector<int> pre(m);

    // Read request indices and store them in the vector
    for (int i = 0; i < n; i++) {
        cin >> req[i];
        // Comment: Read and store request index i
    }

    // Read preemption indices and store them in the vector
    for (int i = 0; i < m; i++) {
        cin >> pre[i];
        // Comment: Read and store preemption index i
    }

    // Initialize index variables for requests and preemptions
    int i = n - 1;
    int j = m - 1;

    // Initialize answer variable
    int ans = 0;

    // While there are still requests and preemptions to compare
    while (i >= 0 && j >= 0) {
        // If the current request can preempt the current preemption
        if (req[i] > pre[j]) {
            // Increment answer variable
            ans++;
        } else {
            // Decrement preemption index
            j--;
        }
        // Decrement request index
        i--;
    }

    // Print the answer and the number of remaining requests
    cout << ans + i + 1;

    return 0;
}

// <END-OF-CODE>
