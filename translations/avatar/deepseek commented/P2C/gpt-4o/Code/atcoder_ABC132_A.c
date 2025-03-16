#include <stdio.h>
#include <string.h>

int main() {
    char S[100];  // Declare a string to hold the input
    int count[256] = {0};  // Array to count frequency of each character
    int uniqueCount = 0;  // To count unique characters

    // Take a string input from the user
    printf("Enter a string: ");
    scanf("%s", S);

    // Count the frequency of each character in the string S
    for (int i = 0; S[i] != '\0'; i++) {
        if (count[(unsigned char)S[i]] == 0) {
            uniqueCount++;  // Increment unique character count
        }
        count[(unsigned char)S[i]]++;  // Increment the frequency of the character
    }

    // Check if the number of unique characters is not equal to 2
    if (uniqueCount != 2) {
        printf("No\n");  // Print "No" and exit if the condition is true
        return 0;  // Exit the program
    }

    // Iterate over the possible characters and check if the frequency of each character is not equal to 2
    for (int i = 0; i < 256; i++) {
        if (count[i] == 2) {
            continue;  // If the frequency is 2, continue to the next character
        }
        if (count[i] > 0) {  // If the character exists and its frequency is not 2
            printf("No\n");  // Print "No" and exit if the condition is true
            return 0;  // Exit the program
        }
    }

    printf("Yes\n");  // Print "Yes" if all characters have a frequency of 2
    return 0;  // Exit the program
}

// <END-OF-CODE>
