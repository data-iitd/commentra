#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> req(n);
    vector<int> pre(m);
    
    // Read elements into req
    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }
    
    // Read elements into pre
    for (int i = 0; i < m; i++) {
        cin >> pre[i];
    }
    
    int i = n - 1, j = m - 1; // Initialize indices i and j
    int ans = 0; // Initialize ans to store the result
    
    // Implement the logic to find the number of elements in req that are greater than the corresponding elements in pre
    while (i >= 0 && j >= 0) {
        if (req[i] > pre[j]) { // If the element in req is greater than the element in pre
            ans++; // Increment ans
        } else {
            j--; // Decrement j to check the next element in pre
        }
        i--; // Decrement i in each iteration
    }
    
    // Print the result which is the sum of ans and the remaining elements in req
    cout << ans + i + 1 << endl;
    
