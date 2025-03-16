
#include <iostream> 
#include <string> 
#include <sstream> 

int main() { 
    // Create a string to store the input from the console
    std::string input; 
    
    // Read a line of input from the console
    std::getline(std::cin, input); 
    
    // Create a stringstream to parse the input string
    std::stringstream ss(input); 
    
    // Create two integer variables to store the initial health and damage dealt per attack
    int h, a; 
    
    // Read the first integer from the input string and store it in the variable h
    ss >> h; 
    
    // Read the second integer from the input string and store it in the variable a
    ss >> a; 
    
    // Initialize a counter to keep track of the number of attacks
    int num = 0; 
    
    // Loop until the health is greater than zero
    for (int i = 1; h > 0; i++) { 
        // Decrease health by the amount of damage dealt
        h = h - a; 
        
        // Increment the attack counter
        num++; 
    } 
    
    // Output the total number of attacks required to reduce health to zero or below
    std::cout << num << std::endl; 
    
    return 0; 
}
