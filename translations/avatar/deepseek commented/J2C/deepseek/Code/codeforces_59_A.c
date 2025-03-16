#include <stdio.h>
#include <ctype.h>

int main() {
    char word[100]; // Declaring a character array to store the input word
    int uppercase = 0; // Initializing the counter for uppercase letters
    int lowercase = 0; // Initializing the counter for lowercase letters

    // Reading a single word from the user input
    scanf("%s", word);

    // Looping through each character in the input word
    for (int i = 0; word[i] != '\0'; i++) {
        if (isupper(word[i])) { // Checking if the character is uppercase
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
    } else if (lowercase > uppercase) {
        for (int i = 0; word[i] != '\0'; i++) {
            putchar(tolower(word[i])); // Printing the word in lowercase if there are more lowercase letters
        }
    } else {
        for (int i = 0; word[i] != '\0'; i++) {
            putchar(tolower(word[i])); // Printing the word in lowercase if the counts are equal
        }
    }

    printf("\n"); // Printing a newline character for formatting
    return 0;
}
