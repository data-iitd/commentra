#include <iostream> 
#include <string> 
#include <sstream> 
using namespace std; 

int main() { 
    // Create a string to hold the input
    string line; 
    
    // Read a line of input from the console
    getline(cin, line); 
    
    // Create a stringstream to parse the input
    stringstream ss(line); 
    
    // Declare variables to hold the input
    int x, a, y; 
    
    // Parse the first three elements of the input into integers
    ss >> x >> a >> y; 
    
    // Initialize a variable to hold the result, defaulting to "NO"
    string h = "NO"; 
    
    // Check if any of the numbers x, a, or y are either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) { 
        // If the sum of x, a, and y equals 17, set the result to "YES"
        if (x + y + a == 17) { 
            h = "YES"; 
        } 
    } 
    
    // Output the result
    cout << h << endl; 
    
    return 0; 
} 

