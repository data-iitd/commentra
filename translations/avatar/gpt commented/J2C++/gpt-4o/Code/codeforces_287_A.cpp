#include <iostream> // Include the iostream library for input and output
#include <string>   // Include the string library for using strings
using namespace std;

int main() {
    // Initializing an array to hold 4 strings
    string str[4];
    
    // Loop to read 4 strings from user input
    for (int i = 0; i < 4; i++) {
        cin >> str[i]; // Read a string and store it in the array
    }
    
    int yes = 0; // Flag to indicate if a condition is met
    
    // Outer loop to iterate through the first 3 strings
    for (int u = 0; u < 3; u++) {
        // Inner loop to check conditions on characters of the strings
        for (int i = 0; i < 3; i++) {
            // Check if the characters in the strings meet the specified conditions
            if ((str[u][i] == str[u][i + 1] && 
                (str[u + 1][i] == str[u][i] || 
                 str[u + 1][i + 1] == str[u][i])) || 
                (str[u + 1][i] == str[u + 1][i + 1] && 
                (str[u][i] == str[u + 1][i] || 
                 str[u][i + 1] == str[u + 1][i]))) ) {
                
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
    
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
