
#include <iostream> 
#include <string> 
#include <vector> 
#include <sstream> 

int main() { 
    // Create a stringstream to read input from the standard input stream
    std::string input_string; 
    std::getline(std::cin, input_string); 
    
    // Create a stringstream to output results to the standard output stream
    std::stringstream ss; 
    
    // Create a vector to store the input strings
    std::vector<std::string> input_vector; 
    
    // Split the input string into a vector of strings based on spaces
    std::string delimiter = " "; 
    size_t pos = 0; 
    std::string token; 
    while ((pos = input_string.find(delimiter))!= std::string::npos) { 
        token = input_string.substr(0, pos); 
        input_vector.push_back(token); 
        input_string.erase(0, pos + delimiter.length()); 
    } 
    input_vector.push_back(input_string); 
    
    // Initialize a counter to keep track of the number of non-zero inputs
    int result = 0; 
    
    // Iterate through each string in the input vector
    for (std::string str : input_vector) { 
        // Increment the counter for each input
        result += 1; 
        
        // If the input is "0", break out of the loop
        if (str == "0") break; 
    } 
    
    // Print the result, which is the count of non-zero inputs before the first "0"
    std::cout << result << std::endl; 
    
    return 0; 
}
