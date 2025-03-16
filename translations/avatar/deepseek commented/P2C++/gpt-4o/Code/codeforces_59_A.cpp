#include <iostream>
#include <string>

int main() {
    std::string txt;  // Declaring a string variable to store user input.
    std::getline(std::cin, txt);  // Taking input from the user and storing it in `txt`.
    
    int cu = 0;  // Initializing the counter for uppercase letters to zero.
    int cl = 0;  // Initializing the counter for lowercase letters to zero.

    // Looping through each character in the input text `txt` to count the number of uppercase and lowercase letters.
    for (char z : txt) {
        if (std::islower(z)) {  // Checking if the current character `z` is lowercase.
            cl++;  // Incrementing the counter for lowercase letters if `z` is lowercase.
        } else {  // If `z` is not lowercase, it must be uppercase.
            cu++;  // Incrementing the counter for uppercase letters.
        }
    }

    // Comparing the counts of uppercase and lowercase letters to decide the case of the output.
    std::string out;  // Declaring a string variable to store the output.
    if (cu > cl) {  // If there are more uppercase letters than lowercase letters.
        out = txt;  // Copying the original text to `out`.
        for (char &c : out) {
            c = std::toupper(c);  // Convert the entire text to uppercase.
        }
    } else {  // If there are more lowercase letters than uppercase letters or equal counts.
        out = txt;  // Copying the original text to `out`.
        for (char &c : out) {
            c = std::tolower(c);  // Convert the entire text to lowercase.
        }
    }

    std::cout << out << std::endl;  // Printing the result stored in `out`.

    return 0;  // Indicating that the program ended successfully.
}

// <END-OF-CODE>
