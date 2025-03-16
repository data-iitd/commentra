#include <iostream> 
#include <cmath> 
#include <iomanip> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    double N, d, x; 
    cin >> N >> d >> x; 
    
    // Initialize a BigDecimal variable to store the accumulated answer
    double ans = 0.0; 
    
    // Loop until N is greater than 0.5
    while (N > 0.5) { 
        // Calculate the current term to be added to the answer
        double adnum = d + x * (N - 0.5); 
        // Add the current term to the accumulated answer
        ans += adnum; 
        
        // Update d using the formula provided
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N); 
        // Update x using the formula provided
        x = (1.0 + (2.0 / N)) * x; 
        
        // Decrement N for the next iteration
        --N; 
    } 
    
    // Create a DecimalFormat object to format the output
    cout << fixed << setprecision(20) << ans << endl; 
    
    return 0; 
} 

