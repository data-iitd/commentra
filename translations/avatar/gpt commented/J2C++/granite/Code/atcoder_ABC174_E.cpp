
#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Set up input and output streams
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    // Create an instance of Solution to solve the problem
    Solution sol; 
    sol.solve(); 

    return 0; 
} 

class Solution { 
public: 
    void solve() { 
        // Read the number of logs and the value of k
        int n, k; 
        cin >> n >> k; 

        // Read the lengths of the logs into a vector
        vector<int> logsLength(n); 
        for (int i = 0; i < n; ++i) 
            cin >> logsLength[i]; 

        // Initialize binary search bounds
        int min = 1, max = (int) 1e9 + 1000; 

        // Perform binary search to find the minimum possible length
        while (min < max) { 
            int mid = (min + max) / 2; 

            // Check if it's possible to cut the logs with the current mid length
            if (nei(mid, logsLength, k)) 
                max = mid; // If possible, search in the lower half
            else 
                min = mid + 1; // Otherwise, search in the upper half
        } 

        // Output the minimum length found
        cout << min << endl; 
    } 

    // Helper method to determine if logs can be cut with the given mid length
    bool nei(int mid, vector<int>& logsLength, int k) { 
        for (int log : logsLength) 
            k -= (log + mid - 1) / mid - 1; // Calculate the number of cuts needed
        
        // Return true if we can make the cuts within the limit of k
        return k >= 0; 
    } 
}; 

// End of code