#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 

using namespace std; 

int main() { 
    // Create a string to store the input
    string input; 
    
    // Read a line of input from the standard input stream
    getline(cin, input); 
    
    // Create a stringstream to parse the input
    stringstream ss(input); 
    
    // Create a vector to store the parsed input
    vector<string> input_array; 
    
    // Iterate through each string in the input array
    while (ss.good()) { 
        // Read a string from the input stream
        string substr; 
        getline(ss, substr, ' '); 
        
        // Add the string to the input array
        input_array.push_back(substr); 
    } 
    
    // Initialize a counter to keep track of the number of non-zero inputs
    int result = 0; 
    
    // Iterate through each string in the input array
    for (string str : input_array) { 
        // Increment the counter for each input
        result += 1; 
        
        // If the input is "0", break out of the loop
        if (str == "0") break; 
    } 
    
    // Print the result, which is the count of non-zero inputs before the first "0"
    cout << result << endl; 
    
    // End the program
    return 0; 
} 

