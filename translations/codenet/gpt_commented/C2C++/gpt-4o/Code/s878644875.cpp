#include <iostream>
#include <cstring>

int main() {
    // Declare two character arrays to hold the input strings
    char s[4], t[4];
    
    // Read the first string from user input
    std::cin >> s;
    
    // Read the second string from user input
    std::cin >> t;
    
    // Initialize a counter to keep track of matching characters
    int hit = 0;
    
    // Loop through the first three characters of both strings
    for (int i = 0; i < 3; i++) {
        // Check if the characters at the same position in both strings match
        if (s[i] == t[i]) 
            hit++; // Increment the hit counter if there's a match
    }
    
    // Output the total number of matching characters
    std::cout << hit << std::endl;
    
    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
