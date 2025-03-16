#include <iostream>
#include <cstring>

int main() {
    // Declare a character array 'c' to store the input string and 'ans' to store the result
    char c[11], ans[11] = {'\0'};
    
    // Read a string input from the user
    std::cin >> c;
    
    // Iterate through each character of the input string until the null terminator is encountered
    for (int i = 0; c[i] != '\0'; i++) {
        // If the current character is not 'B', append it to the 'ans' string
        if (c[i] != 'B') {
            ans[strlen(ans)] = c[i];
        } 
        // If the current character is 'B', remove the last character from 'ans' (if it exists)
        else {
            ans[strlen(ans) - 1] = '\0';
        }
    }
    
    // Print the resulting string after processing the input
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
