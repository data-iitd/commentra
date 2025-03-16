
#include <iostream> 
#include <string> 
using namespace std; 

int main() { 
    // Initialize input and output streams
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false); 
    
    // Read the input string and replace occurrences of "BC" with "D"
    string s; 
    cin >> s; 
    s.replace(s.begin(), s.end(), "BC", "D"); 
    
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
    cout << cnt << endl; 
    
    return 0; 
} 

