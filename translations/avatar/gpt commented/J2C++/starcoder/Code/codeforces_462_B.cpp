#include <bits/stdc++.h>
using namespace std;

// Class to represent each card and implement Comparable for sorting
class c462b { 
    int left = 0; // Count of letters left
    
    @Override 
    public int compareTo(c462b o) { 
        return left - o.left; // Compare based on the count of letters
    } 
}

int main() {
    // Initialize BufferedReader to read input from standard input
    BufferedReader f = new BufferedReader(new InputStreamReader(std::cin)); 
    
    // Initialize PrintWriter to output results to standard output
    PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(std::cout))); 
    
    // Read the first line of input and tokenize it to extract n and k
    string s;
    getline(f, s);
    istringstream iss(s);
    int n, k;
    iss >> n >> k;
    
    // Create an array of c462b objects to count occurrences of each letter
    c462b cards[26];
    for (int i = 0; i < 26; i++) { 
        cards[i] = c462b(); // Initialize each card
    } 
    
    // Read the string of cards and count the occurrences of each letter
    string s;
    getline(f, s);
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
    out << ans << endl; 
    out.close(); // Close the output stream
    return 0;
}

