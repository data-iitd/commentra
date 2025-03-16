#include <iostream>
#include <string>

int main() {
    // Declare a string 'c' to store the input string and 'ans' to store the result
    std::string c, ans = "";
    
    // Read a string input from the user
    std::cin >> c;
    
    // Iterate through each character of the input string until the null terminator is encountered
    for (int i = 0; i < c.length(); i++) {
        // If the current character is not 'B', append it to the 'ans' string
        if (c[i] != 'B') {
            ans += c[i];
        } 
        // If the current character is 'B', remove the last character from 'ans' (if it exists)
        else {
            if (ans.length() > 0) {
                ans.pop_back();
            }
        }
    }
    
    // Print the resulting string after processing the input
    std::cout << ans << std::endl;
}
