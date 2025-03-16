#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_N 100 // Define a maximum size for the number of character arrays
#define MAX_M 100 // Define a maximum size for the length of character arrays

// Function to compare two character arrays aa and bb starting from their respective indices i and j
int compare(char *aa, int i, char *bb, int j, int m) {
    while (m-- > 0) {
        char a = toupper(aa[i]); // Converting the characters to uppercase
        char b = toupper(bb[j]);

        if (a != b) // If characters are not equal, return the difference of their ASCII values
            return a - b;

        i++; // Incrementing the index i in aa
        j++; // Incrementing the index j in bb
    }

    // If all characters match, return 0
    return 0;
}

int main() {
    int n; // Number of character arrays
    scanf("%d", &n); // Reading the number of character arrays to be processed

    char ss[MAX_N][MAX_M]; // 2D array to store the character arrays

    // Reading the character arrays and storing them in the 2D array
    for (int i = 0; i < n; i++) {
        scanf("%s", ss[i]);
    }

    char cc[MAX_M]; // Character array to be compared with the input character arrays
    scanf("%s", cc); // Reading the character array to be compared
    int m = strlen(cc); // Finding the length of the character array cc

    char c; // Character to be matched with the character array cc
    scanf(" %c", &c); // Reading the character
    char c_ = toupper(c); // Converting the character to uppercase
    char a = (c == 'a') ? 'b' : 'a'; // Determining the character a based on the character c
    char a_ = toupper(a); // Converting the character a to uppercase

    int lucky[MAX_M] = {0}; // Array to keep track of the matching indices in cc

    // Iterating through each character in cc and comparing it with all characters in each character array in ss
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int l = strlen(ss[i]); // Finding the length of the character array in ss at the current index i

            if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0) { // Comparison logic
                for (int h = 0; h < l; h++) { // Iterating through each character in the character array in ss at the current index i
                    lucky[j + h] = 1; // Setting the boolean value at the current index j+h in lucky to true
                }
            }
        }
    }

    // Iterating through each character in cc and updating it based on the boolean values in lucky
    for (int j = 0; j < m; j++) {
        if (lucky[j]) { // If the boolean value at the current index j in lucky is true
            if (tolower(cc[j]) == c) { // If the character at the current index j in cc is equal to the character c in lowercase
                cc[j] = isupper(cc[j]) ? a_ : a; // Update the character at the current index j in cc based on the character a
            } else {
                cc[j] = isupper(cc[j]) ? c_ : c; // Update the character at the current index j in cc based on the character c
            }
        }
    }

    // Printing the updated character array cc
    printf("%s\n", cc);

    return 0;
}

// <END-OF-CODE>
