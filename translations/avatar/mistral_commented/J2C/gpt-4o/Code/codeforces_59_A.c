#include <stdio.h>  // Including standard input-output library
#include <ctype.h>  // Including ctype library for character handling

int main() {  // Main function, entry point of the program
    char word[100];  // Declaring a character array to store the input word
    scanf("%s", word);  // Reading the first word as input from the user

    int uppercase = 0;  // Initializing a counter for uppercase characters
    int lowercase = 0;  // Initializing a counter for lowercase characters

    for (int i = 0; word[i] != '\0'; i++) {  // Iterating through each character in the word until the null terminator
        char ch = word[i];  // Assigning the character at the current index to a char variable

        if (isupper(ch)) {  // Checking if the character is uppercase
            uppercase++;  // Incrementing the uppercase counter
        } else if (islower(ch)) {  // Checking if the character is lowercase
            lowercase++;  // Incrementing the lowercase counter
        }
    }

    if (uppercase > lowercase) {  // Checking if there are more uppercase characters than lowercase characters
        for (int i = 0; word[i] != '\0'; i++) {
            putchar(toupper(word[i]));  // Printing the word in uppercase if condition is true
        }
    } else if (lowercase > uppercase) {  // Checking if there are more lowercase characters than uppercase characters
        for (int i = 0; word[i] != '\0'; i++) {
            putchar(tolower(word[i]));  // Printing the word in lowercase if condition is true
        }
    } else {  // If both uppercase and lowercase characters are equal
        for (int i = 0; word[i] != '\0'; i++) {
            putchar(tolower(word[i]));  // Printing the word in lowercase if both conditions are false
        }
    }

    putchar('\n');  // Printing a newline character at the end
    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
