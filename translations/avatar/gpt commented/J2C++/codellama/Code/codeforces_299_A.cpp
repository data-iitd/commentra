#include <iostream> 
#include <algorithm> 
using namespace std; 

int main() { 
    // Read the number of elements in the array
    int n; 
    cin >> n; 
    
    // Initialize an array of size n to store the input values
    int a[n]; 
    
    // Loop to read n integers from the user and store them in the array
    for (int i = 0; i < n; i++) { 
        cin >> a[i]; 
    } 
    
    // Sort the array in ascending order
    sort(a, a + n); 
    
    // Store the minimum value from the sorted array
    int min = a[0]; 
    
    // Check if all elements in the array are divisible by the minimum value
    for (int i = 0; i < n; i++) { 
        if (a[i] % min != 0) { 
            // If any element is not divisible, print -1 and exit
            cout << -1 << endl; 
            return 0; 
        } 
    } 
    
    // If all elements are divisible, print the minimum value
    cout << min << endl; 
    
    return 0; 
} 

