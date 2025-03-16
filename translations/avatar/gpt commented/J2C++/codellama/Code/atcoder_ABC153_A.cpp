#include <iostream> 
#include <string> 
#include <sstream> 
using namespace std; 

int main() { 
    // Create a string to store the input
    string input; 
    
    // Read a line of input from the console
    getline(cin, input); 
    
    // Create a stringstream to parse the input
    stringstream ss(input); 
    
    // Declare variables to store the health and damage
    int h, a; 
    
    // Read the health and damage from the stringstream
    ss >> h >> a; 
    
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
    cout << num << endl; 
    
    return 0; 
} 

