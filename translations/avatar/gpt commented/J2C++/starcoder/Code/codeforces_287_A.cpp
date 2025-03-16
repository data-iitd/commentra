#include <iostream>
#include <string>

using namespace std;

int main() {
    // Creating a Scanner object to read input from the user
    string str[4];
    int i = -1; // Index variable for the first loop
    
    // Loop to read 4 strings from user input
    while (i!= 3) {
        i = i + 1; // Increment index
        cin >> str[i]; // Read a string and store it in the array
    }
    
    int u = -1; // Index variable for the outer loop
    i = -1; // Reset index variable for the inner loop
    int yes = 0; // Flag to indicate if a condition is met
    
    // Outer loop to iterate through the first 3 strings
    while (u!= 2) {
        u = u + 1; // Increment outer index
        i = -1; // Reset inner index
        
        // Inner loop to check conditions on characters of the strings
        while (i!= 2) {
            i = i + 1; // Increment inner index
            
            // Check if the characters in the strings meet the specified conditions
            if ((str[u].at(i) == str[u].at(i + 1) && 
                (str[u + 1].at(i) == str[u].at(i) || 
                 str[u + 1].at(i + 1) == str[u].at(i))) ) || 
                (str[u + 1].at(i) == str[u + 1].at(i + 1) && 
                (str[u].at(i) == str[u + 1].at(i) || 
                 str[u].at(i + 1) == str[u + 1].at(i)))) ) {
                
                yes = 1; // Set flag to indicate a match was found
                cout << "YES" << endl; // Output "YES"
                break; // Exit the inner loop
            }
        }
        
        // If a match was found, exit the outer loop
        if (yes == 1) {
            break;
        }
    }
    
    // If no matches were found, output "NO"
    if (yes == 0) {
        cout << "NO" << endl;
    }
    
    return 0;
}

