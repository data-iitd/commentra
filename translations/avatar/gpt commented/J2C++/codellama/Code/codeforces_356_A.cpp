
#include <bits/stdc++.h> 
using namespace std; 

// FastReader class for efficient input reading
class FastReader { 
    public: 
        string next() { 
            string s; 
            while (getline(cin, s)) { 
                if (s.size() > 0) { 
                    return s; 
                } 
            } 
            return ""; 
        } 
        int nextInt() { 
            return stoi(next()); 
        } 
        long nextLong() { 
            return stol(next()); 
        } 
        double nextDouble() { 
            return stod(next()); 
        } 
        string nextLine() { 
            string s; 
            getline(cin, s); 
            return s; 
        } 
}; 

int main() { 
    // Initialize FastReader to read input efficiently
    FastReader in; 
    
    // Read the number of elements
    int n = in.nextInt(); 
    
    // Create a set to keep track of available positions on the left
    set<int> left; 
    
    // Initialize an array to store the answers
    vector<int> answer(n); 
    
    // Populate the set with indices from 0 to n-1
    for (int i = 0; i < n; i++) { 
        left.insert(i); 
    } 
    
    // Read the number of queries
    int q = in.nextInt(); 
    
    // Process each query
    while (q-- > 0) { 
        // Read the range [l, r] and the winning index
        int l = in.nextInt() - 1; 
        int r = in.nextInt() - 1; 
        int win = in.nextInt(); 
        
        // Update the answer array for all positions in the range [l, r]
        while (left.lower_bound(l) != left.end() && *left.lower_bound(l) <= r) { 
            int curr = *left.lower_bound(l); // Get the smallest index >= l
            answer[curr] = win; // Set the answer for this position
            left.erase(curr); // Remove this position from available positions
        } 
        
        // Mark the winning index as available again
        answer[win - 1] = 0; 
        left.insert(win - 1); // Add the winning index back to available positions
    } 
    
    // Build the output string from the answer array
    string ans = ""; 
    for (int i = 0; i < n; i++) { 
        ans += to_string(answer[i]); // Append each answer to the string
    } 
    
    // Print the final answer
    cout << ans << endl; 
    return 0; 
} 

