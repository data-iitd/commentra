#include <iostream>
#include <string>

int main() {
    // Declaring a variable 's' to store the input string
    std::string s;

    // Reading the string input using 'std::cin'
    std::cin >> s;

    // Declaring a variable 'ans' to store the answer
    int ans = 0;

    // Looping through each character 'c' in the string 's'
    for (char c : s) {
        // Checking if the current character 'c' is equal to '1'
        if (c == '1') {
            // Incrementing the answer if the character is '1'
            ans++;
        }
    }

    // Printing the answer using 'std::cout'
    std::cout << ans << std::endl;

    // End of the code
    return 0;
}
