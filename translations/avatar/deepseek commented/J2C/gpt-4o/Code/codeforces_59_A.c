#include <stdio.h> // Including standard input-output library
#include <ctype.h> // Including ctype library for character handling

int main() {
    char word[100]; // Declaring a character array to store the input word
    scanf("%s", word); // Reading a single word from the user input

    int uppercase = 0; // Initializing the counter for uppercase letters
    int lowercase = 0; // Initializing the counter for lowercase letters

    // Looping through each character in the input word
    for (int i = 0; word[i] != '\0'; i++) {
        char ch = word[i]; // Getting the character at the current position
        if (isupper(ch)) { // Checking if the character is uppercase
            uppercase++; // Incrementing the uppercase counter
        } else {
            lowercase++; // Incrementing the lowercase counter
        }
    }

    // Comparing the counts of uppercase and lowercase letters and printing the result accordingly
    if (uppercase > lowercase) {
        for (int i = 0; word[i] != '\0'; i++) {
            putchar(toupper(word[i])); // Printing the word in uppercase if there are more uppercase letters
        }
    } else {
        for (int i = 0; word[i] != '\0'; i++) {
            putchar(tolower(word[i])); // Printing the word in lowercase if there are more lowercase letters or if they are equal
        }
    }
    putchar('\n'); // Printing a newline at the end

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
