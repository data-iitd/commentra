#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Take a string as input from the user
    char S[100]; // Assuming the maximum length of the string is 99 characters
    scanf("%s", S);

    // Create an array to count the frequency of each character
    int count[256] = {0}; // ASCII characters

    // Count the frequency of each character in the string S
    for (int i = 0; S[i] != '\0'; i++) {
        count[(unsigned char)S[i]]++;
    }

    // Check how many unique characters are in the string
    int uniqueCount = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            uniqueCount++;
        }
    }

    // Check if the number of unique characters is equal to 2
    if (uniqueCount != 2) {
        // If not, print "No" and exit the program
        printf("No\n");
        return 0;
    }

    // Check if each character appears exactly 2 times
    for (int i = 0; i < 256; i++) {
        if (count[i] == 2) {
            continue;
        } else if (count[i] > 0) {
            // If the frequency of any character is not equal to 2, print "No" and exit the program
            printf("No\n");
            return 0;
        }
    }

    // If all characters have a frequency of 2, print "Yes"
    printf("Yes\n");
    return 0;
}

// <END-OF-CODE>
