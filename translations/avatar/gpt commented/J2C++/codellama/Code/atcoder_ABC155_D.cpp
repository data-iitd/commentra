
#include <bits/stdc++.h> 
using namespace std; 

// Define a large prime number for modulo operations
const int mod = 1e9 + 7; 

// Direction vectors for potential grid movements (not used in this code)
int DX[] = { -1, 0, 1, 0 }; 
int DY[] = { 0, -1, 0, 1 }; 

// Variables to store the number of elements, a threshold value, and the array of long integers
int n; 
long k; 
long a[100000]; 

// Function to check if a certain value x can be achieved
bool check(long x) { 
    long tot = 0; // Total count of valid pairs
    
    // Iterate through each element in the array
    for (int i = 0; i < n; i++) { 
        long now = a[i]; // Current element
        int l = 0, r = n; // Initialize binary search bounds
        
        // If the current element is non-negative
        if (now >= 0) { 
            // Perform binary search to count valid pairs
            while (l < r) { 
                int c = (l + r) / 2; 
                if (now * a[c] < x) 
                    l = c + 1; // Move right if the product is less than x
                else 
                    r = c; // Move left otherwise
            } 
            tot += l; // Add the count of valid pairs
        } else { 
            // If the current element is negative
            while (l < r) { 
                int c = (l + r) / 2; 
                if (now * a[c] >= x) 
                    l = c + 1; // Move right if the product is greater than or equal to x
                else 
                    r = c; // Move left otherwise
            } 
            tot += (n - l); // Count valid pairs with negative current element
        } 
        
        // Adjust total count if the product of the element with itself is less than x
        if ((long) a[i] * a[i] < x) 
            tot--; 
    } 
    
    // Return true if the total count of pairs is less than k
    if (tot / 2 < k) 
        return true; 
    else 
        return false; 
} 

int main() { 
    // Initialize scanner for input
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    // Read the number of elements and the threshold value k
    cin >> n >> k; 
    
    // Initialize the array to hold the long integers
    for (int i = 0; i < n; i++) 
        cin >> a[i]; 
    
    // Sort the array to facilitate binary search
    sort(a, a + n); 
    
    // Define a large value for infinity
    long INF = (long) (1e18) + 1; 
    
    // Set the initial bounds for binary search
    long l = -INF; 
    long r = INF; 
    
    // Perform binary search to find the maximum value satisfying the condition
    while (l + 1 < r) { 
        long c = (l + r) / 2; 
        if (check(c)) 
            l = c; // If check returns true, move the lower bound up
        else 
            r = c; // Otherwise, move the upper bound down
    } 
    
    // Output the result
    cout << l << endl; 
    
    return 0; 
} 

