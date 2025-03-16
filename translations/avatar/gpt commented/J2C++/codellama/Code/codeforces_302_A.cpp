#include <iostream> 
#include <cstdio> 
#include <cstring> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the console
    Scanner sc = new Scanner(System.in); 
    
    // Read the number of elements in the array and the number of queries
    int n = sc.nextInt(); 
    int k = sc.nextInt(); 
    
    // Initialize an array to hold the input values
    int arr[] = new int[n]; 
    
    // Populate the array with input values
    for (int i = 0; i < n; i++) 
        arr[i] = sc.nextInt(); 
    
    // StringBuffer to store the results of the queries
    StringBuffer res = new StringBuffer(); 
    
    // Counters for the number of 1s (o) and 0s (e) in the array
    int o = 0, e = 0; 
    
    // Count the number of 1s and 0s in the array
    for (int i = 0; i < n; i++) 
        if (arr[i] == 1) 
            ++o; // Increment count of 1s
        else 
            ++e; // Increment count of 0s
    
    // Process each query
    for (int i = 0; i < k; i++) { 
        // Read the left and right indices for the current query
        int l = sc.nextInt(); 
        int r = sc.nextInt(); 
        
        // Check if the number of elements in the range is odd
        if ((r - l + 1) % 2 == 1) 
            res.append("0\n"); // If odd, append "0" to results
        else { 
            // If even, check if we can form a valid pair of 1s and 0s
            if ((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e) 
                res.append("1\n"); // Append "1" if valid pairs can be formed
            else 
                res.append("0\n"); // Otherwise, append "0"
        } 
    } 
    
    // Output the results of all queries
    System.out.print(res); 
    
    // Close the scanner to free resources
    sc.close(); 
    
    return 0; 
} 

