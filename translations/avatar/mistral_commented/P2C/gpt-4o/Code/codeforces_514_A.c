#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Take an input string `ip` from the user
    char ip[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    scanf("%s", ip);

    // Initialize an empty string `st`
    char st[100] = ""; // Assuming a maximum length of 99 characters + 1 for null terminator

    // Check if the length of the input string is not equal to 1
    if (strlen(ip) != 1) {
        // Check if the first character of the input string is equal to '9'
        if (ip[0] == '9') {
            // Assign '9' to the variable `st`
            strcpy(st, "9");
            // Slice the input string to exclude the first character
            memmove(ip, ip + 1, strlen(ip)); // Move the string left by one character
        }

        // Iterate through each character in the input string `ip`
        for (int i = 0; i < strlen(ip); i++) {
            // If the character is an integer greater than 4
            if (ip[i] > '4') {
                // Calculate the difference between 9 and the integer
                int n = 9 - (ip[i] - '0');
                // Add the difference to the string `st`
                char buffer[2]; // Buffer to hold the character representation of the number
                sprintf(buffer, "%d", n);
                strcat(st, buffer);
            } else {
                // Add the character directly to the string `st`
                strncat(st, &ip[i], 1);
            }
        }
    } else {
        // If the length of the input string is equal to 1
        strcpy(st, ip);
    }

    // Print the integer value of the string `st` to the console
    printf("%d\n", atoi(st));

    return 0;
}

// <END-OF-CODE>
