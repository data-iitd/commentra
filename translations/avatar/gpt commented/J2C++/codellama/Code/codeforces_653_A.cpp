#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

int main() { 
    // Read the number of integers from input
    int n; 
    cin >> n; 
    
    // Initialize a vector to store the integers
    vector<int> a; 
    
    // Read n integers from input and add them to the vector
    for (int i = 0; i < n; i++) { 
        int value; 
        cin >> value; 
        a.push_back(value); 
    } 
    
    // Remove duplicates, sort the vector, and collect it back into a vector
    sort(a.begin(), a.end()); 
    a.erase(unique(a.begin(), a.end()), a.end()); 
    
    // Initialize a flag to check for consecutive triplets
    bool found = false; 
    
    // Check for three consecutive integers in the sorted vector
    for (int i = 0; i < a.size(); i++) { 
        // Ensure there are at least three elements to check
        if (i + 1 < a.size() && i + 2 < a.size()) { 
            // Check if the current, next, and the one after next integers are consecutive
            if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) { 
                found = true; // Set found to true if consecutive triplet is found
            } 
        } 
    } 
    
    // Output "YES" if a triplet was found, otherwise output "NO"
    cout << (found ? "YES" : "NO") << endl; 
    
    return 0; 
} 

