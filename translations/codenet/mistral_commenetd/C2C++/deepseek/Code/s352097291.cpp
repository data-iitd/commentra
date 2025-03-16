#include <iostream>
#include <string>

// Declare variables
std::string c; // An array to store the input string
std::string ans = ""; // An array to store the output string

int main(){
    // Initialize variables
    std::cin >> c; // Read a string from the standard input and store it in the 'c' array

    // Process the string
    for(int i=0;i<c.length();i++){ // Iterate through each character in the string 'c'
        if(c[i]!='B'){ // If the current character is not 'B'
            ans += c[i]; // Append the character to the output string 'ans'
        }
        else{ // If the current character is 'B'
            ans.pop_back(); // Remove the last character from the output string 'ans'
        }
    }

    // Print the output
    std::cout << ans << std::endl; // Print the final output string
}

