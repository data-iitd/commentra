#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of requests and preemptions from the input
    int n, m;
    cin >> n >> m;

    // Create vectors to store request and preemption indices
    vector <int> req(n), pre(m);

    // Read request indices and store them in the vector
    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }

    // Read preemption indices and store them in the vector
    for (int i = 0; i < m; i++) {
        cin >> pre[i];
    }

    // Initialize index variables for requests and preemptions
    int i = n - 1, j = m - 1;

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
    cout << ans << " " << i + 1 << endl;
}

