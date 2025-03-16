#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[100]; // Declaring a character array to store the input word
    int uppercase = 0, lowercase = 0; // Declaring two integer variables to store the counts of uppercase and lowercase letters
    
    // Reading a single word from the user input
    printf("Enter a word: ");
    scanf("%s", word);
    
    // Looping through each character in the input word
    for (int i = 0; i < strlen(word); i++) {
        char ch = word[i]; // Getting the character at the current position
        if (isupper(ch)) { // Checking if the character is uppercase
            uppercase++; // Incrementing the uppercase counter
        } else {
            lowercase++; // Incrementing the lowercase counter
        }
    }
    
    // Comparing the counts of uppercase and lowercase letters and printing the result accordingly
    if (uppercase > lowercase) {
        printf("%s\n", toupper(word)); // Printing the word in uppercase if there are more uppercase letters
    } else if (lowercase > uppercase) {
        printf("%s\n", tolower(word)); // Printing the word in lowercase if there are more lowercase letters
    } else {
        printf("%s\n", tolower(word)); // Printing the word in lowercase if the counts are equal
    }
    
    return 0;
}

