
#include <iostream> 
#include <map> 
#include <string> 
#include <vector> 

using namespace std; 

int main() { 
    // Create an instance of FastScanner to read input efficiently
    FastScanner input; 
    
    // Read the number of integers
    int n = input.nextInt(); 
    
    // Create a HashMap to store the frequency of each integer
    map<int, int> map; 
    
    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) { 
        int val = input.nextInt(); 
        map[val] = map.count(val) + 1; 
    } 
    
    // Initialize max to the smallest possible integer value
    int max = INT_MIN; 
    
    // Iterate through the hash map to find the maximum count
    for (map<int, int>::iterator it = map.begin(); it != map.end(); it++) { 
        int value = it->second; 
        max = max > value ? max : value; 
    } 
    
    // Print the maximum count and the size of the hash map
    cout << max << " " << map.size() << endl; 
    
    return 0; 
} 

// Utility class to read input efficiently
class FastScanner { 
    public: 
        FastScanner() { 
            cin.tie(NULL); 
            ios_base::sync_with_stdio(false); 
        } 
        
        // Method to read the next token
        string next() { 
            string str; 
            cin >> str; 
            return str; 
        } 
        
        // Method to read the next integer
        int nextInt() { 
            return stoi(next()); 
        } 
        
        // Method to read the next long
        long nextLong() { 
            return stol(next()); 
        } 
        
        // Method to read the next double
        double nextDouble() { 
            return stod(next()); 
        } 
        
        // Method to read the next line
        string nextLine() { 
            string str; 
            getline(cin, str); 
            return str; 
        } 
}; 

