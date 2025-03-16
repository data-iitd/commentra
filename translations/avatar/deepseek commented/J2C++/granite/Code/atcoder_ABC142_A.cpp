

#include <bits/stdc++.h>

// Include statements to handle input/output operations and mathematical calculations

int main() {
    // Main method is the entry point of the program
    
    try {
        std::string input;
        std::getline(std::cin, input);
        
        // Reading a string value from the input
        
        double countOdd = std::round(std::stod(input) / 2);
        
        // Calculating the number of odd numbers up to the given input
        
        double result = countOdd / std::stod(input);
        
        // Using double to handle decimal calculations
        
        std::cout << std::fixed << std::setprecision(10) << result << std::endl;
        
        // Printing the result
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
        
        // Handling any potential exceptions to ensure program termination
        
    }
    
    return 0;
    
    // End of the program
}

