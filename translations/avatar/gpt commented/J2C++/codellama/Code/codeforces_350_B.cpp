#include <iostream> 
#include <string> 
#include <sstream> 
using namespace std; 

int main() { 
    // Read the number of elements
    int n; 
    cin >> n; 
    
    // Initialize arrays to store input values and counts
    int a[n + 1]; 
    int b[n + 1]; 
    int num[n + 1]; 
    
    // Read values into array a
    for (int i = 1; i <= n; i++) 
        cin >> a[i]; 
    
    // Read values into array b
    for (int i = 1; i <= n; i++) 
        cin >> b[i]; 
    
    // Count occurrences of each value in array b
    for (int i = 1; i <= n; i++) 
        num[b[i]]++; 
    
    // Initialize variables for tracking the longest sequence and its representation
    string ss = ""; 
    int ans = 0; 
    bool st[n + 1]; 
    
    // Iterate through each element to find the longest valid sequence
    for (int i = 1; i <= n; i++) { 
        // Check if the current element in a is 1
        if (a[i] == 1) { 
            st[i] = true; // Mark this index as visited
            stringstream sb; 
            int x = b[i]; // Start with the corresponding value in b
            stringstream sss; 
            sss << i; // Append the current index
            sb << " " << sss.str().c_str(); // Reverse and append to the sequence
            
            int s = 1; // Initialize the length of the current sequence
            
            // Continue to build the sequence while conditions are met
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) { 
                sss.str(""); 
                sss << x; // Append the next index
                sb << " " << sss.str().c_str(); // Reverse and append to the sequence
                st[x] = true; // Mark this index as visited
                x = b[x]; // Move to the next index in b
                s++; // Increment the sequence length
            } 
            
            // Update the longest sequence found if the current one is longer
            if (s > ans) { 
                ans = s; 
                ss = sb.str().c_str(); // Store the longest sequence
            } 
        } 
    } 
    
    // Output the length of the longest sequence and the sequence itself
    cout << ans << endl; 
    cout << ss << endl; 
    
    return 0; 
} 

