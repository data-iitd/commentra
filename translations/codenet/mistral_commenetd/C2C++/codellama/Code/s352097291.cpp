
#include <iostream>
#include <string>

// Declare variables
std::string c; // A string to store the input string
std::string ans; // A string to store the output string

int main(){
    // Initialize variables
    std::cin >> c; // Read a string from the standard input and store it in the 'c' string

    // Process the string
    for(int i=0;i<c.length();i++){ // Iterate through each character in the string 'c'
        if(c[i]!='B'){ // If the current character is not 'B'
            ans += c[i]; // Append the character to the output string 'ans'
        }
        else{ // If the current character is 'B'
            ans.erase(ans.length()-1); // Remove the last character from the output string 'ans'
        }
    }

    // Print the output
    std::cout << ans << std::endl; // Print the final output string
}

// The comments explain the purpose of each logical block and make the code more readable.

