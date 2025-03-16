#include <iostream> 
#include <cmath> 

using namespace std; 

int main() { 
    // Create a Scanner object to read input from the console
    int A, B, amari, result; 
    cin >> A >> B; 
    
    // Initialize variables to hold the remainder and the result
    amari = 0; 
    result = 0; 
    
    // Calculate the initial result based on the formula (B - 1) / (A - 1)
    result = (B - 1) / (A - 1); 
    
    // Calculate the remainder when (B - 1) is divided by (A - 1)
    amari = (B - 1) % (A - 1); 
    
    // If there is a remainder, increment the result by 1
    if (amari != 0) { 
        result += 1; 
    } 
    
    // Print the final result to the console
    cout << result << endl; 
    
    // Close the Scanner to free resources
    return 0; 
} 

