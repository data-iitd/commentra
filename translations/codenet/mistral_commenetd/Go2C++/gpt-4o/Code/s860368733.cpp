#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// main function is the entry point of the program
int main() {
    // Initialize variables
    int n, m;
    // Read input from standard input
    cin >> n >> m;
    // Allocate memory for h vector
    vector<int> h(n);
    // Read h vector elements from standard input
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        // Comment for the loop that reads h vector elements
        // from standard input and stores them in the h vector
    }
    // Initialize counter set
    unordered_set<int> counter;
    // Read m query pairs from standard input
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // Check the condition for a and b
        if (h[a - 1] < h[b - 1]) {
            // Add a to the counter set if h[a-1] is smaller than h[b-1]
            counter.insert(a);
        } else if (h[a - 1] > h[b - 1]) {
            // Add b to the counter set if h[a-1] is greater than h[b-1]
            counter.insert(b);
        } else {
            // Add both a and b to the counter set if h[a-1] is equal to h[b-1]
            counter.insert(a);
            counter.insert(b);
        }
        // Comment for the loop that processes m query pairs
    }
    // Print the result
    cout << n - counter.size() << endl;
    // Comment for the final print statement
}

// <END-OF-CODE>
