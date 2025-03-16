#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

// Define a constant for infinity
const int INF = 1e9 + 5; 

int main() { 
    // Create a Scanner object for input
    int n; 
    cin >> n; 
    
    // Initialize two vectors to store the pairs
    vector<int> a; 
    vector<int> b; 
    
    // Initialize left to infinity and right to zero
    int left = INF, right = 0; 
    
    // Read the pairs and determine the minimum and maximum values
    for (int i = 0; i < n; i++) { 
        int x, y; 
        cin >> x >> y; 
        a.push_back(x); 
        b.push_back(y); 
        
        // Update left to the minimum value found in a
        left = min(left, x); 
        // Update right to the maximum value found in b
        right = max(right, y); 
    } 
    
    // Check for a pair that matches the left and right bounds
    for (int i = 0; i < n; i++) { 
        // If the current pair matches the min and max values
        if (left == a[i] && right == b[i]) { 
            // Print the index (1-based) and exit
            cout << i + 1 << endl; 
            return 0; 
        } 
    } 
    
    // If no matching pair is found, print -1
    cout << -1 << endl; 
    return 0; 
} 

