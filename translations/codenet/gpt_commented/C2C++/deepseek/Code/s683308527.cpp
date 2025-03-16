#include <iostream>
#include <string>

int main() {
    int n; // Variable to store the number of lines to read
    std::string s; // String to store each line of input

    // Read the number of lines to process
    std::cin >> n;
    std::cin.ignore(); // Ignore the newline character

    // Loop to process each line of input
    while(n--) {
        // Read a line of input from stdin
        std::getline(std::cin, s);

        // Search for the substring "Hoshino" in the input line
        // Replace the character following "Hoshino" with 'a'
        std::string::size_type pos = 0;
        while((pos = s.find("Hoshino", pos)) != std::string::npos) {
            s[pos + 6] = 'a'; // Replace the character after "Hoshino" with 'a'
            pos += 1; // Move to the next character to avoid infinite loop
        }

        // Print the modified line
        std::cout << s << std::endl;
    }

    return 0; // Return 0 to indicate successful completion
}
