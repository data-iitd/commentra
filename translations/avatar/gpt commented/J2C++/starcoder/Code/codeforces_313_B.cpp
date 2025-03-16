#include <bits/stdc++.h> 
using namespace std; 

class Fast { 
    public: 
    void sol(std::istream& cin, std::ostream& cout) { 
        // Read the first line of input and tokenize it to get the string
        string s; 
        cin >> s; 
        
        // Initialize a cumulative array to count consecutive characters
        int cum[s.length() + 1]; 
        cum[0] = cum[s.length()] = 0; 
        
        // Fill the cumulative array with counts of consecutive characters
        for (int i = 1; i < s.length(); i++) { 
            if (s[i] == s[i - 1]) 
                cum[i] = cum[i - 1] + 1; // Increment count if the current character is the same as the previous
            else 
                cum[i] = cum[i - 1]; // Carry forward the previous count if different
        } 
        
        // Read the number of queries from the input
        int q; 
        cin >> q; 
        
        // Process each query
        while (q--!= 0) { 
            // Read the range for the query
            int l, r; 
            cin >> l >> r; 
            
            // Calculate and print the result for the current query
            cout << cum[r] - cum[l - 1] << endl; 
        } 
    } 
}

