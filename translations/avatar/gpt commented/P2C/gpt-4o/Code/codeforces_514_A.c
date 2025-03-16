#include <stdio.h>
#include <string.h>

int main() {
    // Get user input
    char ip[100]; // Assuming the input will not exceed 99 characters
    scanf("%s", ip);

    // Initialize an empty string to store the transformed number
    char st[100] = ""; // Output string
    int len = strlen(ip);

    // Check if the input length is not equal to 1
    if (len != 1) {
        // If the first character is '9', keep it and remove it from the input
        if (ip[0] == '9') {
            strcat(st, "9"); // Start the output string with '9'
            // Shift the input string to remove the first character
            memmove(ip, ip + 1, len - 1);
            ip[len - 1] = '\0'; // Null-terminate the new string
        }

        // Iterate through each character in the remaining input
        for (int i = 0; ip[i] != '\0'; i++) {
            // If the digit is greater than 4, calculate its complement to 9
            if (ip[i] > '4') {
                int n = 9 - (ip[i] - '0'); // Calculate the complement
                char buffer[2];
                sprintf(buffer, "%d", n); // Convert the number to string
                strcat(st, buffer); // Append the complement to the output string
            } else {
                // If the digit is 4 or less, keep it unchanged
                char buffer[2] = {ip[i], '\0'};
                strcat(st, buffer); // Append the original digit to the output string
            }
        }
    } else {
        // If the input length is 1, simply assign it to the output
        strcpy(st, ip);
    }

    // Print the final transformed number as an integer
    printf("%d\n", atoi(st));

    return 0;
}

// <END-OF-CODE>
