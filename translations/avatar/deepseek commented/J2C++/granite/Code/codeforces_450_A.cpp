

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Read the first integer input, which represents the number of elements
    queue <int> q1; // Initialize queue to store the elements
    queue <int> q2; // Initialize queue to store the indices
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x; // Read each element and add it to q1
        q1.push(x); // Add the corresponding index to q2
        q2.push(i); // Add the index to q2
    }
    
    int ans = 0; // Initialize ans to store the result
    
    while (!q1.empty()) { // Continue the loop until q1 is empty
        if (q1.front() <= m) { // Check if the front element of q1 is less than or equal to m
            q1.pop(); // Remove the front element from q1
            ans = q2.front(); // Assign the corresponding index to ans and remove it from q2
            q2.pop(); // Remove the index from q2
        } else if (q1.front() > m) { // Check if the front element of q1 is greater than m
            int x = q1.front(); // Remove the front element from q1
            q1.pop();
            int val = x - m; // Subtract m from the element
            q1.push(val); // Add the result back to q1
            int val2 = q2.front(); // Remove the corresponding index from q2
            q2.pop();
            q2.push(val2); // Add the index back to the end of q2
        }
    }
    
    cout << ans << endl; // Print the index of the last remaining element
    
    return 0;
}
