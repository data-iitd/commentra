#include <stdio.h>
#include <string.h>

int main() {
    char ip[100];
    char st[100];
    int i;

    // Take an input string `ip` from the user
    scanf("%s", ip);

    // Initialize an empty string `st`
    st[0] = '\0';

    // Check if the length of the input string is not equal to 1
    if (strlen(ip) != 1) {

        // Check if the first character of the input string is equal to "9"
        if (ip[0] == '9') {
            strcpy(st, "9");
            // Slice the input string to exclude the first character
            for (i = 1; i < strlen(ip); i++) {
                ip[i - 1] = ip[i];
            }
            ip[strlen(ip) - 1] = '\0';
        }

        // Iterate through each character in the input string `ip`
        for (i = 0; i < strlen(ip); i++) {

            // If the character is an integer greater than 4
            if (ip[i] > '4') {
                // Calculate the difference between 9 and the integer
                int n = 9 - (ip[i] - '0');
                // Add the difference to the string `st`
                char temp[2];
                sprintf(temp, "%d", n);
                strcat(st, temp);

            } else {
                // Add the character directly to the string `st`
                char temp[2];
                temp[0] = ip[i];
                temp[1] = '\0';
                strcat(st, temp);
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
