
#include <iostream>
#include <string>

int main() {
    // Declare a variable to hold the input string
    std::string a;
    
    // Read input from the user and store it in variable 'a'
    std::cin >> a;
    
    // Initialize a variable 'ans' with the default value "Good"
    std::string ans = "Good";
    
    // Loop through the first three characters of the string 'a'
    for (int i = 0; i < 3; i++) {
        // Check if the current character is the same as the next character
        if (a[i] == a[i+1]) {
            // If they are the same, set 'ans' to "Bad"
            ans = "Bad";
        }
    }
    
    // Print the final result stored in 'ans'
    std::cout << ans << std::endl;
    
    // End of code
    return 0;
}

