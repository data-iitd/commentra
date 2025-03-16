#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of elements (n) and the maximum size of the queue (b)
    int n, b;
    cin >> n >> b;
    
    // Initialize an array to store the results
    long ans[n];
    
    // Create a queue for managing time values
    queue<long> q;
    
    // Process each element based on the input
    for (int i = 0; i < n; i++) {
        // Read the time (t) and duration (d) for the current element
        int t, d;
        cin >> t >> d;
        
        // Remove elements from the front of the queue that are no longer valid (i.e., their time is less than or equal to t)
        while (!q.empty() && q.front() <= t) {
            q.pop();
        }
        
        // Check if the size of the queue is within the allowed limit
        if (q.size() <= b) {
            // If the queue is empty, set the answer to the current time (t) plus duration (d)
            // Otherwise, set it to the last element in the queue plus duration (d)
            ans[i] = (q.empty()? t : q.back()) + d;
            
            // Add the computed answer to the queue
            q.push(ans[i]);
        } else {
            // If the queue size exceeds the limit, set the answer to -1
            ans[i] = -1;
        }
    }
    
    // Print the results stored in the ans array
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}

