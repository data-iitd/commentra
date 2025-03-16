

#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Set up input and output streams
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    // Read the input string from the user
    string str; 
    getline(cin, str); 

    // Create a unordered_map to count the frequency of each character in the input string
    unordered_map<char, int> map; 

    // Initialize a counter for characters with odd frequencies
    int oddCount = 0; 

    // Iterate through the input string to populate the frequency map
    for (int i = 0; i < str.length(); i++) { 
        char ch = str[i]; 
        if (map.find(ch)!= map.end()) { 
            map[ch]++; 
        } else { 
            map[ch] = 1; 
        } 
    } 

    // Iterate through the map to count characters with odd frequencies
    for (auto const& [key, value] : map) { 
        if (value % 2!= 0) { 
            oddCount++; 
        } 
    } 

    // Determine the winner based on the count of characters with odd frequencies
    if (oddCount <= 1 || oddCount % 2!= 0) { 
        cout << "First" << endl; 
    } else { 
        cout << "Second" << endl; 
    } 

    return 0; 
}
