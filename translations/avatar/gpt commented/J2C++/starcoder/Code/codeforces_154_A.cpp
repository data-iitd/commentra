#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Create a BufferedReader to read input from the standard input stream
    cin.sync_with_stdio(0); 
    cin.tie(0); 
    BufferedReader infile = new BufferedReader(new InputStreamReader(cin)); 
    
    // Read the first line of input and convert it to a character array
    char arr[] = infile.readLine().toCharArray(); 
    
    // Get the length of the character array
    int N = arr.length; 
    
    // Initialize a HashSet to store unique strings (not used in this code)
    unordered_set<string> set; 
    
    // Read the number of queries K
    int K = stoi(infile.readLine()); 
    
    // Initialize the result counter
    int res = 0; 
    
    // Loop through each query
    for (int k = 0; k < K; k++) { 
        // Read the input string for the current query
        string input = infile.readLine(); 
        
        // Initialize counters for characters in the input string
        int a = 0; 
        int b = 0; 
        
        // Iterate through the character array
        for (int i = 0; i < N; i++) { 
            // Count occurrences of the first character of the input string
            if (arr[i] == input[0]) 
                a++; 
            // Count occurrences of the second character of the input string
            else if (arr[i] == input[1]) 
                b++; 
            // If neither character is found, update the result and reset counters
            else { 
                res += min(a, b); 
                a = b = 0; 
            } 
        } 
        // Add the minimum count of the two characters to the result
        res += min(a, b); 
    } 
    
    // Output the final result
    cout << res << endl; 
}

