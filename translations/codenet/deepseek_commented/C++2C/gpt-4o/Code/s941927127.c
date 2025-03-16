#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main(void) {
    // Step 1: Declare necessary variables
    char W[100]; // Assuming the maximum length of the string is 99 characters
    scanf("%s", W);
    
    // Step 2: Read input
    // The program reads a string `W` from the standard input.
    
    // Step 3: Sort the string
    // The string `W` is sorted in ascending order.
    size_t len = strlen(W);
    qsort(W, len, sizeof(char), compare);

    // Step 4: Check for character pairs
    // The program iterates through the sorted string, checking if each character
    // is followed by its identical pair.
    for (size_t i = 0; i < len; i += 2) {
        if (W[i] != W[i + 1]) {
            // If a character is not followed by its pair, output "No" and exit.
            printf("No\n");
            return 0;
        }
    }
    
    // Step 5: Output result
    // If all characters are in pairs, the program outputs "Yes"; otherwise,
    // it outputs "No".
    printf("Yes\n");
    
    return 0;
}

// <END-OF-CODE>
