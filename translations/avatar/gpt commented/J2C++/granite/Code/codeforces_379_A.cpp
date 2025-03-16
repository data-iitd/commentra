
#include <iostream> // Importing the utility package for using Scanner

int main() {
    // Creating a Scanner object to read input from the user
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    
    int a, b; // Declaring two integers to store the input values
    
    // Reading two integers from the user
    std::cin >> a >> b;
    
    // Initializing the result with the value of 'a'
    int res = a; 
    
    // Loop to perform the division and accumulate the result
    while (a >= b) {
        // Add the quotient of a divided by b to the result
        res += (a / b);
        
        // Update 'a' to be the sum of the quotient and the remainder
        a = (a / b) + (a % b);
    }
    
    // Output the final result
    std::cout << res << std::endl;
    
    return 0;
}
