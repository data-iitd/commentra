#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[1000];  // Declare a character array to store the input string
    scanf("%s", S);  // Read the input string

    int c[256] = {0};  // Declare an array to count the frequency of each character
    for (int i = 0; i < strlen(S); i++) {
        c[(int)S[i]]++;  // Increment the count for the character
    }

    int unique_chars = 0;  // Initialize a counter for unique characters
    int char_set[256] = {0};  // Array to keep track of unique characters
    for (int i = 0; i < strlen(S); i++) {
        if (char_set[(int)S[i]] == 0) {
            char_set[(int)S[i]] = 1;  // Mark the character as seen
            unique_chars++;  // Increment the unique characters counter
        }
    }

    // Check if the number of unique characters is not equal to 2
    if (unique_chars != 2) {
        printf("No\n");  // Print "No" and exit if the condition is true
        return 0;  // Exit the program
    }

    // Check if the frequency of each character is not equal to 2
    for (int i = 0; i < 256; i++) {
        if (char_set[i] && c[i] != 2) {
            printf("No\n");  // Print "No" and exit if the condition is true
            return 0;  // Exit the program
        }
    }

    printf("Yes\n");  // Print "Yes" if all characters have a frequency of 2
    return 0;  // Exit the program
}
