#include <iostream> 
#include <string> 
#include <map> 
#include <set> 
using namespace std; 

// Function to check if the characters in s2 are all present in s1
bool isValid(string s1, string s2) { 
    int n1 = s1.length(); 
    int n2 = s2.length(); 
    // Create a HashMap to store characters from the first string
    map<char, bool> map; 
    
    // Add all characters from the first string to the map
    for (int i = 0; i < n1; i++) { 
        map[s1[i]] = true; 
    } 
    
    // Check if all characters in the second string are present in the first string
    for (int i = 0; i < n2; i++) { 
        if (map.find(s2[i]) == map.end()) return false; 
    } 
    return true; // All characters are valid
} 

// Function to calculate the minimum frequency of each character present in both strings
int minFrequency(string s1, string s2) { 
    int n1 = s1.length(); 
    int n2 = s2.length(); 
    // Create HashMaps to count the frequency of characters in both strings
    map<char, int> m1; 
    map<char, int> m2; 
    
    // Count the frequency of each character in the first string
    for (int i = 0; i < n1; i++) { 
        m1[s1[i]]++; 
    } 
    
    // Count the frequency of each character in the second string
    for (int i = 0; i < n2; i++) { 
        m2[s2[i]]++; 
    } 
    
    // Initialize a variable to hold the result
    int ans = 0; 
    // Create a HashSet to track unique characters from the second string
    set<char> hs; 
    
    // Calculate the minimum frequency of each character present in both strings
    for (int i = 0; i < n2; i++) { 
        if (hs.find(s2[i]) == hs.end()) { 
            hs.insert(s2[i]); 
            int x1 = m1[s2[i]]; // Frequency in the first string
            int x2 = m2[s2[i]]; // Frequency in the second string
            x1 = min(x1, x2); // Take the minimum frequency
            ans += x1; // Add to the result
        } 
    } 
    return ans; // Return the final result
} 

// Main function
int main() { 
    // Create a Scanner object to read input from the console
    string s1, s2; 
    cin >> s1 >> s2; 
    
    // Validate the input strings; if invalid, print -1 and exit
    if (isValid(s1, s2) == false) { 
        cout << -1 << endl; 
    } else { 
        // Calculate the minimum frequency of each character present in both strings
        int ans = minFrequency(s1, s2); 
        // Print the final result
        cout << ans << endl; 
    } 
    return 0; 
} 

