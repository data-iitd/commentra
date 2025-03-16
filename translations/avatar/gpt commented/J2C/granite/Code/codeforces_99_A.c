
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    // Read input from the user and convert it to a character array
    char str[1000];
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = 0;

    // Initialize variable to store the index of the decimal point
    int dotIndex = 0;

    // Find the index of the decimal point in the input
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            dotIndex = i;
            break;
        }
    }

    // Check if the digit before the decimal point is '9'
    if (str[dotIndex - 1] == '9') {
        // If it is, print a specific message
        printf("GOTO Vasilisa.\n");
    }
    // Check if the digit after the decimal point is greater than 4
    else if (str[dotIndex + 1] - '0' > 4) {
        // If it is, create a new string from the integer part and add 1
        char _str[1000];
        strncpy(_str, str, dotIndex);
        _str[dotIndex] = 0;
        printf("%s\n", (char *) (atoi(_str) + 1));
    }
    // If the digit after the decimal point is 4 or less
    else {
        // Print the integer part as it is
        for (int i = 0; i < dotIndex; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }

    return 0;
}
