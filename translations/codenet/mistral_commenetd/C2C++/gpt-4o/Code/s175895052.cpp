#include <iostream>
#include <cstring> // For using strlen

// The main function is the starting point of the program
int main() {
    char n[10]; // A character array of size 10 is declared to store the input string

    // The cin function is used to read a string of characters from the standard input stream
    std::cin >> n;

    // Check if the first three characters of the input string form an identical sequence
    if (((n[0] == n[1]) && (n[1] == n[2])) || ((n[1] == n[2]) && (n[2] == n[3]))) {
        // If the condition is true, print "Yes" to the standard output stream
        std::cout << "Yes" << std::endl;
    } else {
        // If the condition is false, print "No" to the standard output stream
        std::cout << "No" << std::endl;
    }

    // The program returns an integer value 0 upon successful execution
    return 0;
}

// <END-OF-CODE>
