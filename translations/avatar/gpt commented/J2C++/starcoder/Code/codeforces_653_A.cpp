#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Use try-with-resources to ensure Scanner and PrintWriter are closed automatically
    try (Scanner in = new Scanner(cin); 
        PrintWriter out = new PrintWriter(cout)) { 
        // Read the number of integers from input
        int n = in.nextInt(); 
        // Initialize a list to store the integers
        vector<int> a; 
        
        // Read n integers from input and add them to the list
        for (int i = 0; i < n; i++) { 
            int value = in.nextInt(); 
            a.push_back(value); 
        } 
        
        // Remove duplicates, sort the list, and collect it back into a list
        a = vector<int>(unique(a.begin(), a.end())); 
        sort(a.begin(), a.end()); 
        
        // Initialize a flag to check for consecutive triplets
        bool found = false; 
        
        // Check for three consecutive integers in the sorted list
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
        out.println(found? "YES" : "NO"); 
    } 
}

