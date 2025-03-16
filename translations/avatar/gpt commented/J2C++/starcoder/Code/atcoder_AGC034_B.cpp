#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Initialize input and output streams
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    
    // Create a Scanner object for reading input
    cin.exceptions(ios::failbit); 
    string s; 
    cin >> s; 
    
    // Initialize counters for 'A' and the result
    long cnt = 0; 
    long tmp = 0; 
    
    // Iterate through the modified string to count occurrences
    for (int i = 0; i < s.length(); i++) { 
        // Increment temporary counter for 'A'
        if (s[i] == 'A') { 
            tmp++; 
        } 
        // Add the count of 'A's to the result when 'D' is encountered
        else if (s[i] == 'D') { 
            cnt += tmp; 
        } 
        // Reset the temporary counter for any other character
        else { 
            tmp = 0; 
        } 
    } 
    
    // Output the final count of valid pairs
    cout << cnt << "\n"; 
} 

