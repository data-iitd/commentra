
#include <iostream>
#include <string>

int main() {
    // Declare a string variable to store the input
    std::string a;
    
    // Read a string input from the user and store it in `a`
    std::cin >> a;
    
    // Initialize the variable `ans` with the value "Good"
    std::string ans = "Good";
    
    // Loop through the first three characters of the string `a`
    for (int i = 0; i < 3; i++) {
        // Check if the current character is the same as the next character
        if (a[i] == a[i+1]) {
            // If the condition is true, change the value of `ans` to "Bad"
            ans = "Bad";
        }
    }
    
    // Print the value of `ans`
    std::cout << ans << std::endl;
    
    return 0;
}
