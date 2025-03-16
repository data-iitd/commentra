
#include <stdio.h> // Include the standard input/output library
#include <ctype.h> // Include the character classification library

int main() {
    char word[100]; // Declare a character array to store the input word
    int uppercase = 0; // Initialize a counter for uppercase letters
    int lowercase = 0; // Initialize a counter for lowercase letters
    
    // Prompt the user to enter a word
    printf("Enter a word: ");
    scanf("%s", word);
    
    // Loop through each character in the input word
    for (int i = 0; word[i]!= '\0'; i++) {
        char ch = word[i]; // Get the character at the current index
        
        // Check if the character is uppercase
        if (isupper(ch)) {
            uppercase++; // Increment the uppercase counter
        } else {
            lowercase++; // Increment the lowercase counter
        }
    }
    
    // Compare the counts of uppercase and lowercase letters
    if (uppercase > lowercase) {
        // If there are more uppercase letters, print the word in uppercase
        for (int i = 0; word[i]!= '\0'; i++) {
            word[i] = toupper(word[i]); // Convert the character to uppercase
        }
        printf("%s\n", word); // Print the word in uppercase
    } else if (lowercase > uppercase) {
        // If there are more lowercase letters, print the word in lowercase
        for (int i = 0; word[i]!= '\0'; i++) {
            word[i] = tolower(word[i]); // Convert the character to lowercase
        }
        printf("%s\n", word); // Print the word in lowercase
    } else {
        // If the counts are equal, print the word in lowercase
        printf("%s\n", word); // Print the word in lowercase
    }
    
    return 0; // Return 0 to indicate successful execution
}

