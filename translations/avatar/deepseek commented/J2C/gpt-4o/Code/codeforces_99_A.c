#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read input string from the user
    char str[100]; // Assuming the input will not exceed 99 characters
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if present
    str[strcspn(str, "\n")] = 0;

    // Find the index of the dot ('.') in the string
    int dotIndex = 0;
    while (str[dotIndex] != '.' && str[dotIndex] != '\0') {
        dotIndex++;
    }

    // Check if the character before the dot is '9'
    if (str[dotIndex - 1] == '9') {
        printf("GOTO Vasilisa.\n");
    }
    // If the character before the dot is not '9', check the digit after the dot
    else if (str[dotIndex + 1] > '4') {
        // Increment the number before the dot by 1 and print the result
        char beforeDot[100];
        strncpy(beforeDot, str, dotIndex);
        beforeDot[dotIndex] = '\0'; // Null-terminate the string

        // Convert to integer and increment
        long long number = atoll(beforeDot);
        number += 1;

        printf("%lld\n", number);
    }
    // If the digit after the dot is 4 or less, print the number before the dot without any changes
    else {
        for (int i = 0; i < dotIndex; i++) {
            putchar(str[i]);
        }
        putchar('\n');
    }

    return 0;
}
