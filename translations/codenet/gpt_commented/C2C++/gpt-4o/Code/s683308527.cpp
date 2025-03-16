#include <iostream>
#include <string>

int main() {
    int n; // Variable to store the number of lines to read
    std::string s; // String to store each line of input
    std::string target = "Hoshino"; // Substring to search for

    // Read the number of lines to process
    std::cin >> n;
    std::cin.ignore(); // Ignore the newline character after the number

    // Loop to process each line of input
    while (n--) {
        // Read a line of input from stdin
        std::getline(std::cin, s);

        // Search for the substring "Hoshino" in the input line
        size_t pos = 0;
        while ((pos = s.find(target, pos)) != std::string::npos) {
            if (pos + target.length() < s.length()) {
                s[pos + target.length()] = 'a'; // Replace the character after "Hoshino" with 'a'
            }
            pos += target.length(); // Move past the current occurrence
        }

        // Print the modified line
        std::cout << s << std::endl;
    }

    return 0; // Return 0 to indicate successful completion
} // <END-OF-CODE>
