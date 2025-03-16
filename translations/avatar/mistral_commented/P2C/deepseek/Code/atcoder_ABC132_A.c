#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[100];
    int c[256] = {0}; // Array to store the frequency of each character
    int unique_chars = 0;

    // Take a string as input from the user
    scanf("%s", S);

    // Calculate the frequency of each character in the string
    for (int i = 0; i < strlen(S); i++) {
        c[(unsigned char)S[i]]++;
    }

    // Create a set of unique characters
    char unique_set[256] = {0};
    for (int i = 0; i < strlen(S); i++) {
        if (c[(unsigned char)S[i]] > 0 && unique_set[(unsigned char)S[i]] == 0) {
            unique_set[(unsigned char)S[i]] = 1;
            unique_chars++;
        }
    }

    // Check if the number of unique characters is equal to 2
    if (unique_chars != 2) {
        printf("No\n");
        return 0;
    }

    // Check if each unique character has a frequency of 2
    for (int i = 0; i < 256; i++) {
        if (unique_set[i] == 1 && c[i] != 2) {
            printf("No\n");
            return 0;
        }
    }

    // If all characters have a frequency of 2, print "Yes"
    printf("Yes\n");

    return 0;
}
