
#include <stdio.h> // Include the standard input/output library
#include <ctype.h> // Include the character classification library

int main() {
    char word[100]; // Declare a character array to store the input word
    printf("Enter a word: "); // Prompt the user to enter a word
    scanf("%s", word); // Read the word from the user input
    
    int uppercase = 0; // Initialize the counter for uppercase letters
    int lowercase = 0; // Initialize the counter for lowercase letters
    
    // Loop through each character in the input word
    for (int i = 0; word[i]!= '\0'; i++) {
        if (isupper(word[i])) { // Check if the character is uppercase
            uppercase++; // Increment the uppercase counter
        } else {
            lowercase++; // Increment the lowercase counter
        }
    }
    
    // Compare the counts of uppercase and lowercase letters and print the result accordingly
    if (uppercase > lowercase) {
        for (int i = 0; word[i]!= '\0'; i++) {
            word[i] = toupper(word[i]); // Convert the word to uppercase
        }
        printf("%s\n", word); // Print the word in uppercase
    } else if (lowercase > uppercase) {
        for (int i = 0; word[i]!= '\0'; i++) {
            word[i] = tolower(word[i]); // Convert the word to lowercase
        }
        printf("%s\n", word); // Print the word in lowercase
    } else {
        for (int i = 0; word[i]!= '\0'; i++) {
            word[i] = tolower(word[i]); // Convert the word to lowercase
        }
        printf("%s\n", word); // Print the word in lowercase
    }
    
    return 0; // Return 0 to indicate successful execution
}
