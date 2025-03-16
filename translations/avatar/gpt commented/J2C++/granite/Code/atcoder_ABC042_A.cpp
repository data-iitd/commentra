
#include <iostream> 
#include <string> 
#include <sstream> 

int main() { 
    // Create a stringstream to read input from the console
    std::string line; 
    std::getline(std::cin, line); 
    std::stringstream ss(line); 
    
    // Read three integers from the input stringstream
    int x, a, y; 
    ss >> x >> a >> y; 
    
    // Initialize a variable to hold the result, defaulting to "NO"
    std::string h = "NO"; 
    
    // Check if any of the numbers x, a, or y are either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) { 
        // If the sum of x, a, and y equals 17, set the result to "YES"
        if (x + y + a == 17) { 
            h = "YES"; 
        } 
    } 
    
    // Output the result
    std::cout << h << std::endl; 
    
    return 0; 
}
