#include <iostream> // Include the iostream library for input and output
#include <string>   // Include the string library for string manipulation

int main() {
    std::string s; // Declare a variable 's' to hold the input string
    std::cin >> s; // Read a string from standard input and store it in 's'

    // Count the occurrences of the letter 'o' in the input string 's'
    int n = std::count(s.begin(), s.end(), 'o');

    // Calculate the result based on the count of 'o' and print it
    // The formula adds 700 to 100 times the count of 'o'
    std::cout << 700 + n * 100 << std::endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
