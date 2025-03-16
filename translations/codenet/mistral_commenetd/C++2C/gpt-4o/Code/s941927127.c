#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main(void) {
    char W[100]; // Declare a character array to store the input word

    // Read the input word from the standard input stream using scanf
    scanf("%s", W);

    // Get the length of the string W
    int len = strlen(W);

    // Sort the characters in the string W in ascending order using qsort
    qsort(W, len, sizeof(char), compare);

    // Loop through the sorted string W
    for (int i = 0; i < len - 1; i++) {
        // Check if the current character and the next character in the string are the same
        if (W[i] != W[i + 1]) {
            // If they are not the same, print "No" and return from the main function
            printf("No\n");
            return 0;
        }
    }

    // If the loop completes without finding any pair of non-identical characters, print "Yes"
    printf("Yes\n");

    // Return 0 to indicate successful execution of the main function
    return 0;
}

// <END-OF-CODE>
