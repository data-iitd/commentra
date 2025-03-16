
#include <bits/stdc++.h> 
using namespace std; 

// Function to check if the characters in s2 are all present in s1
bool isValid(string s1, string s2) { 
    int n1 = s1.length(); 
    int n2 = s2.length(); 
    // Create a HashMap to store characters from the first string
    unordered_map<char, bool> map; 
    
    // Add all characters from the first string to the map
    for (char c : s1) { 
        map[c] = true; 
    } 
    
    // Check if all characters in the second string are present in the first string
    for (char c : s2) { 
        if (!map[c]) return false; 
    } 
    return true; // All characters are valid
} 

// Main function
int main() { 
    // Create a Scanner object to read input from the console
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Read two strings from the input
    string s1, s2; 
    cin >> s1 >> s2; 
    
    // Validate the input strings; if invalid, print -1 and exit
    if (isValid(s1, s2) == false) { 
        cout << -1 << endl; 
    } else { 
        // Create HashMaps to count the frequency of characters in both strings
        unordered_map<char, int> m1; 
        unordered_map<char, int> m2; 
        
        // Count the frequency of each character in the first string
        for (char c : s1) { 
            if (m1.find(c)!= m1.end()) { 
                m1[c]++; 
            } else { 
                m1[c] = 1; 
            } 
        } 
        
        // Count the frequency of each character in the second string
        for (char c : s2) { 
            if (m2.find(c)!= m2.end()) { 
                m2[c]++; 
            } else { 
                m2[c] = 1; 
            } 
        } 
        
        // Initialize a variable to hold the result
        int ans = 0; 
        // Create a HashSet to track unique characters from the second string
        unordered_set<char> hs; 
        
        // Calculate the minimum frequency of each character present in both strings
        for (char c : s2) { 
            if (hs.find(c) == hs.end()) { 
                hs.insert(c); 
                int x1 = m1[c]; // Frequency in the first string
                int x2 = m2[c]; // Frequency in the second string
                x1 = min(x1, x2); // Take the minimum frequency
                ans += x1; // Add to the result
            } 
        } 
        // Print the final result
        cout << ans << endl; 
    } 
    return 0; 
} 
