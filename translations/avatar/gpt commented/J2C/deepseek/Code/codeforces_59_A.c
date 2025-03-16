#include <stdio.h>
#include <ctype.h>

int main() {
    char word[100];
    int uppercase = 0;
    int lowercase = 0;
    
    // Reading a word from the user
    scanf("%s", word);
    
    // Looping through each character in the input word
    for (int i = 0; word[i] != '\0'; i++) {
        if (isupper(word[i])) {
            uppercase++; // Incrementing the uppercase counter
        } else {
            lowercase++; // Incrementing the lowercase counter
        }
    }
    
    // Comparing the counts of uppercase and lowercase letters
    if (uppercase > lowercase) {
        // If there are more uppercase letters, print the word in uppercase
        for (int i = 0; word[i] != '\0'; i++) {
            printf("%c", toupper(word[i]));
        }
    } else if (lowercase > uppercase) {
        // If there are more lowercase letters, print the word in lowercase
        for (int i = 0; word[i] != '\0'; i++) {
            printf("%c", tolower(word[i]));
        }
    } else {
        // If the counts are equal, print the word in lowercase
        for (int i = 0; word[i] != '\0'; i++) {
            printf("%c", tolower(word[i]));
        }
    }
    
    printf("\n"); // Printing a newline character
    return 0;
}
