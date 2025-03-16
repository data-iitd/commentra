#include <stdio.h> // Including standard input-output library
#include <ctype.h> // Including ctype library for character handling

int main() {
    // Declaring a variable to hold the input word
    char word[100]; // Assuming the maximum length of the word is 99 characters
    // Prompting the user to enter a word
    printf("Enter a word: ");
    scanf("%s", word); // Reading the input word

    // Initializing counters for uppercase and lowercase letters
    int uppercase = 0;
    int lowercase = 0;

    // Looping through each character in the input word
    for (int i = 0; word[i] != '\0'; i++) {
        char ch = word[i]; // Getting the character at the current index

        // Checking if the character is uppercase
        if (isupper(ch)) {
            uppercase++; // Incrementing the uppercase counter
        } else {
            lowercase++; // Incrementing the lowercase counter
        }
    }

    // Comparing the counts of uppercase and lowercase letters
    if (uppercase > lowercase) {
        // If there are more uppercase letters, print the word in uppercase
        for (int i = 0; word[i] != '\0'; i++) {
            putchar(toupper(word[i]));
        }
        putchar('\n');
    } else if (lowercase > uppercase) {
        // If there are more lowercase letters, print the word in lowercase
        for (int i = 0; word[i] != '\0'; i++) {
            putchar(tolower(word[i]));
        }
        putchar('\n');
    } else {
        // If the counts are equal, print the word in lowercase
        for (int i = 0; word[i] != '\0'; i++) {
            putchar(tolower(word[i]));
        }
        putchar('\n');
    }

    return 0; // Indicating successful completion
}

// <END-OF-CODE>
