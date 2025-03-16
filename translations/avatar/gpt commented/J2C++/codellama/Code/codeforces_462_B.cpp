#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std; 

int main() { 
    // Initialize variables to read input from standard input
    int n, k; 
    string s; 
    cin >> n >> k >> s; 
    
    // Create an array of c462b objects to count occurrences of each letter
    c462b cards[26]; 
    for (int i = 0; i < 26; i++) { 
        cards[i].left = 0; // Initialize each card
    } 
    
    // Count the occurrences of each letter
    for (int t = 0; t < n; t++) { 
        cards[s[t] - 'A'].left++; // Increment the count for the corresponding letter
    } 
    
    long ans = 0; // Variable to store the final answer
    
    // Perform k operations to maximize the score
    for (int i = 0; i < k; i++) { 
        sort(cards, cards + 26); // Sort the cards based on the count of letters
        
        // Determine the number of changes to make for the most frequent letter
        long change = min(cards[25].left, k - i); 
        ans += change * change; // Update the answer with the square of changes
        
        // Decrease the count of the most frequent letter by the number of changes made
        cards[25].left -= change; 
        i += change - 1; // Adjust the loop counter based on changes made
    } 
    
    // Output the final result
    cout << ans << endl; 
    return 0; 
} 

// Class to represent each card and implement Comparable for sorting
class c462b { 
public: 
    int left = 0; // Count of letters left
    
    bool operator<(const c462b& o) const { 
        return left < o.left; // Compare based on the count of letters
    } 
};

