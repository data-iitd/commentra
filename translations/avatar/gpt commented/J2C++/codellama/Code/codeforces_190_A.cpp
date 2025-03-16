#include <iostream> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the console
    int n, m; 
    cin >> n >> m; 
    
    // Check if n is zero
    if (n == 0) { 
        // If m is not zero, print "Impossible" since we cannot form a valid output
        if (m != 0) 
            cout << "Impossible"; 
        // If m is also zero, print "0 0" as the valid output
        else 
            cout << 0 << " " << 0; 
        return 0; 
    } 
    
    // Check if m is less than or equal to n
    if (m <= n) { 
        // If m is zero, set it to one to ensure valid output
        if (m == 0) { 
            m = 1; 
        } 
        // Print n and the adjusted value of m
        cout << n << " " << (m + n - 1); 
        return 0; 
    } 
    
    // If m is greater than n, print m and the adjusted value of m
    cout << m << " " << (m + n - 1); 
    return 0; 
} 

