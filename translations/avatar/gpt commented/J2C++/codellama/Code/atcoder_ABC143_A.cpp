#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 

using namespace std; 

int main() { 
    try { 
        // Create a string to hold the input
        string input; 
        
        // Read a line of input from the console
        getline(cin, input); 
        
        // Create a stringstream to parse the input
        stringstream ss(input); 
        
        // Create a vector to hold the parsed integers
        vector<int> numbers; 
        
        // Read the first and second integers from the stringstream
        int a, b; 
        ss >> a >> b; 
        
        // Calculate the value of c based on the formula: c = a - b * 2
        int c = a - b * 2; 
        
        // If c is negative, set it to 0
        if (c < 0) c = 0; 
        
        // Output the final value of c
        cout << c << endl; 
    } catch (exception e) { 
        // Handle any exceptions that may occur during input or processing
    } 
    
    // End of code
    return 0; 
}


