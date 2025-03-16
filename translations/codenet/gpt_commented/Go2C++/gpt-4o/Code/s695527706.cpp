#include <iostream> // Include the iostream library for input and output
#include <string>   // Include the string library for string manipulation functions

int main() {
    int n;                // Declare a variable n to hold the length of the string
    std::string s;      // Declare a variable s to hold the input string

    // Read input values for n and s from the standard input
    std::cin >> n >> s;

    // Count the number of occurrences of the substring "ABC" in the string s
    int count = 0;
    std::string substring = "ABC";
    size_t pos = s.find(substring); // Find the first occurrence of "ABC"

    // Loop to count all occurrences of "ABC"
    while (pos != std::string::npos) {
        count++; // Increment the count
        pos = s.find(substring, pos + 1); // Find the next occurrence
    }

    // Print the count
    std::cout << count << std::endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
