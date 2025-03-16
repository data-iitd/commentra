#include <iostream> // Including the iostream library for input and output
#include <cctype>   // Including the cctype library for character classification
#include <string>   // Including the string library for string operations

int main() {
    std::string word; // Declaring a string variable to hold the input word
    std::cin >> word; // Reading a single word from the user input

    int uppercase = 0; // Initializing the counter for uppercase letters
    int lowercase = 0; // Initializing the counter for lowercase letters

    // Looping through each character in the input word
    for (char ch : word) {
        if (std::isupper(ch)) { // Checking if the character is uppercase
            uppercase++; // Incrementing the uppercase counter
        } else {
            lowercase++; // Incrementing the lowercase counter
        }
    }

    // Comparing the counts of uppercase and lowercase letters and printing the result accordingly
    if (uppercase > lowercase) {
        std::cout << word; // Printing the word in uppercase if there are more uppercase letters
        std::transform(word.begin(), word.end(), word.begin(), ::toupper); // Convert to uppercase
    } else if (lowercase > uppercase) {
        std::cout << word; // Printing the word in lowercase if there are more lowercase letters
        std::transform(word.begin(), word.end(), word.begin(), ::tolower); // Convert to lowercase
    } else {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower); // Convert to lowercase if the counts are equal
    }

    std::cout << std::endl; // Printing a newline at the end
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
