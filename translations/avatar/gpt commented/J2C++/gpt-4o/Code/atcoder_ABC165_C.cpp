#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Declare global variables to hold input values and variables for dimensions and result
vector<int> a, b, c, d;
int n = 0;
int m = 0;
int q = 0;
long long ans = -100LL; // Initialize answer to a very low value

void dfs(vector<int>& list) {
    // Check if the current list has reached the required size (n)
    if (list.size() == n) {
        long long score = 0LL; // Initialize score for the current configuration
        
        // Calculate the score based on the queries
        for (int i = 0; i < q; ++i) {
            // If the condition is met, add the corresponding value to the score
            score += (list[b[i]] - list[a[i]] == c[i]) ? d[i] : 0LL;
        }
        
        // Update the maximum score if the current score is higher
        ans = max(ans, score);
        return;
    }
    
    // If the list is not empty, continue adding numbers from the last added number to m
    if (!list.empty()) {
        for (int num = list.back(); num <= m; ++num) {
            list.push_back(num); // Add the current number to the list
            dfs(list);           // Recur with the updated list
            list.pop_back();     // Backtrack by removing the last number
        }
    } else {
        // If the list is empty, start adding numbers from 1 to m
        for (int num = 1; num <= m; ++num) {
            list.push_back(num); // Add the current number to the list
            dfs(list);           // Recur with the updated list
            list.pop_back();     // Backtrack by removing the last number
        }
    }
}

int main() {
    // Create a Scanner object for input
    cin >> n >> m >> q;
    
    // Initialize arrays based on the number of queries (q)
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    
    // Read the query parameters into the arrays
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; // Store a[i] (0-indexed)
        b[i]--; // Store b[i] (0-indexed)
    }
    
    // Start the depth-first search (DFS) to find the maximum score
    vector<int> list;
    dfs(list);
    
    // Output the maximum score found
    cout << ans << endl;
    
    return 0;
}

// <END-OF-CODE>
