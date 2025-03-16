#include <iostream>  // Include necessary headers
#include <string>    // Include necessary headers

int main() {
    int n;  // Declare an integer to store the number of lines
    std::string s;  // Declare a string to store the input line
    std::getline(std::cin, s);  // Read the number of lines
    n = std::stoi(s);  // Convert the first line to an integer

    while (n--) {  // Loop through each line
        std::getline(std::cin, s);  // Read the input line
        size_t pos = 0;  // Initialize position for searching
        while ((pos = s.find("Hoshino", pos)) != std::string::npos) {  // Find "Hoshino"
            s.replace(pos, 6, "Hoshina");  // Replace "Hoshino" with "Hoshina"
            pos += 6;  // Move past the replaced substring
        }
        std::cout << s << std::endl;  // Print the modified line
    }
    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
