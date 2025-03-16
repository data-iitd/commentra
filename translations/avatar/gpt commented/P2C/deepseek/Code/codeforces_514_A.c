#include <stdio.h>
#include <string.h>

int main() {
    char ip[100];
    char st[100];
    int i;

    // Get user input
    fgets(ip, sizeof(ip), stdin);

    // Remove newline character if present
    if (ip[strlen(ip) - 1] == '\n') {
        ip[strlen(ip) - 1] = '\0';
    }

    // Initialize an empty string to store the transformed number
    st[0] = '\0';

    // Check if the input length is not equal to 1
    if (strlen(ip) != 1) {
        // If the first character is '9', keep it and remove it from the input
        if (ip[0] == '9') {
            st[0] = '9'; // Start the output string with '9'
            for (i = 1; i < strlen(ip); i++) {
                ip[i - 1] = ip[i]; // Remove the first character from the input
            }
            ip[strlen(ip) - 1] = '\0'; // Null-terminate the remaining string
        }

        // Iterate through each character in the remaining input
        for (i = 0; i < strlen(ip); i++) {
            // If the digit is greater than 4, calculate its complement to 9
            if (ip[i] > '4') {
                int n = '9' - ip[i]; // Calculate the complement
                st[i] = n + '0'; // Append the complement to the output string
            } else {
                // If the digit is 4 or less, keep it unchanged
                st[i] = ip[i]; // Append the original digit to the output string
            }
        }
        st[strlen(ip)] = '\0'; // Null-terminate the output string
    } else {
        // If the input length is 1, simply assign it to the output
        strcpy(st, ip);
    }

    // Print the final transformed number as an integer
    printf("%d\n", atoi(st));

    return 0;
}
