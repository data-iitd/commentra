#include <stdio.h>
#include <string.h>

int main() {
    char ip[100];  // Declaring a character array to store the input.
    char st[100];  // Declaring a character array to store the result.
    int len, i;

    // Taking an input from the user and storing it in the array `ip`.
    fgets(ip, sizeof(ip), stdin);

    // Removing the newline character if present.
    if (ip[strlen(ip) - 1] == '\n') {
        ip[strlen(ip) - 1] = '\0';
    }

    // Initializing the string `st` to an empty string.
    st[0] = '\0';

    // Getting the length of the input `ip`.
    len = strlen(ip);

    // Checking if the length of the input `ip` is not equal to 1.
    if (len != 1) {
        // Checking if the first character of `ip` is "9".
        if (ip[0] == '9') {
            strcpy(st, "9");
            for (i = 1; i < len; i++) {
                ip[i - 1] = ip[i];
            }
            ip[len - 1] = '\0';
        }
        // Iterating over the remaining characters in `ip`.
        for (i = 0; i < len; i++) {
            // Checking if the integer value of the character is greater than 4.
            if (ip[i] - '0' > 4) {
                int n = 9 - (ip[i] - '0');  // Calculating the difference between 9 and the integer value.
                char temp[2];
                sprintf(temp, "%d", n);  // Converting it to a string.
                strcat(st, temp);  // Appending it to `st`.
            } else {
                // Simply appending the character to `st`.
                char temp[2];
                sprintf(temp, "%c", ip[i]);
                strcat(st, temp);
            }
        }
    } else {  // If the length of `ip` is 1.
        strcpy(st, ip);  // Assigning `ip` directly to `st`.
    }

    // Printing the integer value of `st`.
    printf("%d\n", atoi(st));

    return 0;
}
