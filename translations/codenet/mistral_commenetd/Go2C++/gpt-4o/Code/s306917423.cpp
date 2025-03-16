#include <iostream> // Including the iostream library for input/output operations
#include <string>   // Including the string library for string operations

int main() {
    // Declaring a variable 's' of type 'string' to store the input string
    std::string s;

    // Reading the string input using 'std::cin'
    std::cin >> s;

    // Declaring a variable 'ans' of type 'int' to store the answer
    int ans = 0; // Initializing the answer to zero

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

// <END-OF-CODE>
