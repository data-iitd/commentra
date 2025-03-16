#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    // Create a variable to read input from the console
    int n, m;
    
    // Read the number of strings (n) and the number of queries (m)
    cin >> n >> m;
    
    // Initialize a vector to store the strings
    vector<string> arrs(n);
    
    // Read n strings from the input
    for (int i = 0; i < n; i++) {
        cin >> arrs[i];
    }
    
    // Initialize a vector to store the lengths of segments between 'G' and 'S'
    vector<int> length(n);
    int index = 0;
    int returnDex = 0;
    
    // Iterate through each string to find the indices of 'G' and 'S'
    for (const string& tmp : arrs) {
        int dexG = tmp.find('G'); // Find the index of 'G'
        int dexS = tmp.find('S'); // Find the index of 'S'
        
        // If 'G' appears after 'S', set returnDex to -1
        if (dexG > dexS) {
            returnDex = -1;
        }
        
        // Calculate the length between 'G' and 'S' and store it in the length vector
        length[index++] = dexS - dexG;
    }
    
    // Use an unordered_set to store unique lengths
    unordered_set<int> set;
    
    // Add each length to the unordered_set to ensure uniqueness
    for (int len : length) {
        set.insert(len);
    }
    
    // Check if returnDex was set to -1 and print the appropriate result
    if (returnDex == -1) {
        cout << returnDex << endl; // Print -1 if 'G' is after 'S' in any string
    } else {
        cout << set.size() << endl; // Print the number of unique lengths
    }
    
    return 0;
}

// <END-OF-CODE>
