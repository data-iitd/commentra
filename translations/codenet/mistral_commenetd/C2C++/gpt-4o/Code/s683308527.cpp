#include <iostream> // Include standard input/output library
#include <cstring>  // Include string manipulation library

int main() { // Start of the main function
    int n; // Declare an integer variable 'n' to store the number of strings to be processed
    char s[10010]; // Declare a character array 's' of size 10010 to store each string read from the input
    char *c; // Declare a character pointer 'c' to traverse the string 's'

    std::cin >> n; // Read an integer 'n' from the standard input
    std::cin.ignore(); // Ignore the newline character after reading 'n'

    while (n--) { // Start of the while loop that processes each string
        std::cin.getline(s, 1010); // Read a string of maximum length 1000 from the standard input into the character array 's'

        while (c = strstr(s, "Hoshino")) { // Start of the inner while loop that replaces the substring "Hoshino" with "aana"
            *(c + 6) = 'a'; // Replace the 7th character of the substring "Hoshino" with 'a'
            *(c + 7) = 'a'; // Replace the 8th character of the substring "Hoshino" with 'a'
            *(c + 8) = 'a'; // Replace the 9th character of the substring "Hoshino" with 'a'
            *(c + 9) = 'n'; // Replace the 10th character of the substring "Hoshino" with 'n' to get the substring "aana"
        }

        std::cout << s; // Print the modified string to the standard output
    }

    return 0; // End of the main function with a return value of 0 indicating successful execution
}

// <END-OF-CODE>
