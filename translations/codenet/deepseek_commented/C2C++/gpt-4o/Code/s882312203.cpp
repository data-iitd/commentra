#include <iostream> // Include iostream for input-output operations
#include <cstring>  // Include cstring for strlen function

int main(int argc, char *argv[]) {
    char s[26]; // Declare a character array to store the input string, with a maximum size of 26 characters

    std::cin >> s; // Read a string from the user input and store it in the array s

    // Outer loop to iterate over each character in the string s using index j
    for (int j = 0; j < strlen(s); j++) {
        // Inner loop to iterate over each character in the string s using index i
        for (int i = 0; i < strlen(s); i++) {
            // Check if the characters at positions i and j are the same, but only if i is not equal to j
            if ((i != j) && (s[i] == s[j])) {
                std::cout << "no" << std::endl; // Print "no" if a duplicate character is found and exit the program
                return 0;
            }
        }
    }

    std::cout << "yes" << std::endl; // Print "yes" if no duplicates are found after completing the loops

    return 0; // Return 0 to indicate successful execution of the program
}

// <END-OF-CODE>
