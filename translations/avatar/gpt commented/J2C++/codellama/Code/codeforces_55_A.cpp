#include <iostream> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    Scanner scan; 
    
    // Declare variables
    int n, i = 1, k = 0, p = 1; 
    bool flag = true; 
    int a[1000]; // Array to keep track of occurrences
    
    // Read an integer input from the user
    cin >> n; 
    
    // Initialize the array
    for (int i = 0; i < 1000; i++) { 
        a[i] = 0; 
    } 
    
    // Loop through the input
    while (i <= n) { 
        // Check if the number is already in the array
        if (a[i] == 0) { 
            // If not, add it to the array
            a[i] = 1; 
            k++; 
        } 
        // If the number is already in the array, increment the count
        else { 
            a[i]++; 
        } 
        
        // Check if the count is greater than the previous maximum
        if (k > p) { 
            p = k; 
        } 
        
        // Increment the loop counter
        i++; 
    } 
    
    // Print the maximum number of occurrences
    cout << p << endl; 
    
    return 0; 
} 

