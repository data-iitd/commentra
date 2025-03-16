#include <iostream> 
#include <vector> 

using namespace std; 

int main() { 
    // Create a Scanner to read input from the console
    Scanner sc(cin); 
    
    // Read the number of elements N and the number of groups M
    int N = sc.nextInt(); 
    int M = sc.nextInt(); 
    
    // Create an ArrayList to store bitwise representations for each element
    vector<int> a(N, 0); 
    
    // Initialize the ArrayList with zeros for N elements
    for (int i = 0; i < N; i++) { 
        a[i] = 0; 
    } 
    
    // Read M groups of integers and update the bitwise representation
    for (int i = 0; i < M; i++) { 
        int k = sc.nextInt(); // Read the number of integers in the current group
        for (int j = 0; j < k; j++) { 
            int s = sc.nextInt(); // Read the integer
            s--; // Convert to zero-based index
            // Update the bitwise representation for the element
            a[s] |= (1 << i); 
        } 
    } 
    
    // Read M integers to create a bitmask p
    int p = 0; 
    for (int i = 0; i < M; i++) { 
        int x = sc.nextInt(); // Read the integer
        p |= (x << i); // Update the bitmask p
    } 
    
    // Initialize a counter for valid combinations
    int ans = 0; 
    
    // Iterate through all possible subsets of N elements
    for (int s = 0; s < (1 << N); s++) { 
        int t = 0; // Initialize a temporary variable to store the XOR result
        for (int i = 0; i < N; i++) { 
            // Check if the i-th element is included in the subset
            if (((s >> i) & 1) == 1) { 
                // XOR the current element's bitwise representation
                t ^= a[i]; 
            } 
        } 
        // Check if the XOR result matches the bitmask p
        if (p == t) { 
            ans++; // Increment the count of valid combinations
        } 
    } 
    
    // Output the total count of valid combinations
    cout << ans << endl; 
    
    // Close the scanner to free resources
    sc.close(); 
    
    return 0; 
} 

