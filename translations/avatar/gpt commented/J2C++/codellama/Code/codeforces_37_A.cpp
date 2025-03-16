
#include <iostream> 
#include <map> 
#include <string> 
#include <vector> 

using namespace std; 

int main() { 
    // Create a FastScanner object to read input efficiently
    FastScanner input; 
    
    // Read the number of integers to be processed
    int n; 
    cin >> n; 
    
    // Initialize a HashMap to store the frequency of each integer
    map<int, int> map; 
    
    // Loop through the input integers and populate the frequency map
    for (int i = 0; i < n; i++) { 
        int val; 
        cin >> val; 
        // Update the count of the integer in the map
        map[val]++; 
    } 
    
    // Initialize a variable to track the maximum frequency found
    int max = INT_MIN; 
    
    // Iterate through the entries in the frequency map to find the maximum frequency
    for (auto entry : map) { 
        int value = entry.second; 
        // Update max if the current frequency is greater than the current max
        max = max > value ? max : value; 
    } 
    
    // Print the maximum frequency and the number of unique integers
    cout << max << " " << map.size() << endl; 
    
    return 0; 
} 

// FastScanner class for efficient input reading
class FastScanner { 
    public: 
        FastScanner() { 
            cin.tie(NULL); 
            ios_base::sync_with_stdio(false); 
        } 
        
        // Method to get the next token from input
        string next() { 
            string token; 
            cin >> token; 
            return token; 
        } 
        
        // Method to read the next integer from input
        int nextInt() { 
            return stoi(next()); 
        } 
        
        // Method to read the next long from input
        long nextLong() { 
            return stol(next()); 
        } 
        
        // Method to read the next double from input
        double nextDouble() { 
            return stod(next()); 
        } 
        
        // Method to read the next line from input
        string nextLine() { 
            string line; 
            getline(cin, line); 
            return line; 
        } 
}; 

