

#include <iostream>
#include <string>

int main() {
    // Declare a string variable 'a' to store user input
    std::string a;

    // Read user input using std::cin and store it in variable 'a'
    std::cin >> a;

    // Initialize a string variable 'ans' with value "Good"
    std::string ans = "Good";

    // Loop through each character in the string 'a' for 3 times
    for (int i = 0; i < 3; i++) {
        // Check if the current character is same as next character
        if (a[i] == a[i+1]) {
            // Update the value of 'ans' if current and next character are same
            ans = "Bad";
        }
    }

    // Print the final value of 'ans'
    std::cout << ans << std::endl;

    return 0;
}
