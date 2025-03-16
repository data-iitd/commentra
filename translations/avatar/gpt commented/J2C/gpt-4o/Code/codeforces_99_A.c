#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read input from the user
    char str[100]; // Assuming the input will not exceed 99 characters
    scanf("%s", str);
    
    // Initialize variable to store the index of the decimal point
    int dotIndex = -1;
    
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
    else if (dotIndex + 1 < strlen(str) && (str[dotIndex + 1] - '0') > 4) {
        // If it is, create a new string from the integer part and add 1
        char _str[100];
        strncpy(_str, str, dotIndex);
        _str[dotIndex] = '\0'; // Null-terminate the string
        
        // Convert to integer and add 1
        long long int value = atoll(_str) + 1;
        printf("%lld\n", value);
    }
    // If the digit after the decimal point is 4 or less
    else {
        // Print the integer part as it is
        for (int i = 0; i < dotIndex; i++) {
            putchar(str[i]);
        }
        putchar('\n');
    }
    
    return 0;
}

// <END-OF-CODE>
