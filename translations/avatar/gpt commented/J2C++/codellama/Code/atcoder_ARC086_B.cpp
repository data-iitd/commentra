
#include <iostream> 
#include <cmath> 
#include <vector> 

using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    int n; 
    cin >> n; 
    
    // Initialize an array of size n to hold the integers
    int a[n]; 
    
    // Populate the array with user input
    for (int i = 0; i < n; ++i) 
        cin >> a[i]; 
    
    // Create a list to store the result pairs
    vector<string> r; 
    
    // Variable to track the index of the element with the maximum absolute value
    int m = 0; 
    
    // Find the index of the element with the maximum absolute value
    for (int i = 1; i < n; ++i) 
        if (abs(a[m]) < abs(a[i])) 
            m = i; 
    
    // Generate pairs of indices based on the sign of the maximum absolute value element
    for (int i = 0; i < n; ++i) 
        if (a[m] >= 0 ^ a[i] >= 0) 
            r.push_back(to_string(m + 1) + " " + to_string(i + 1)); 
    
    // If the maximum absolute value element is non-negative
    if (a[m] >= 0) { 
        // Add pairs of consecutive indices in ascending order
        for (int i = 1; i < n; ++i) 
            r.push_back(to_string(i) + " " + to_string(i + 1)); 
    } else { 
        // If the maximum absolute value element is negative, add pairs in descending order
        for (int i = n; i > 1; --i) 
            r.push_back(to_string(i) + " " + to_string(i - 1)); 
    } 
    
    // Print the size of the result list
    cout << r.size() << endl; 
    
    // Print each pair in the result list
    for (int i = 0; i < r.size(); ++i) 
        cout << r[i] << endl; 
    
    return 0; 
} 

