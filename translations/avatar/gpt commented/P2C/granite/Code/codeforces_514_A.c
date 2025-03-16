
#include <stdio.h>
#include <string.h>

int main() {
    char ip[100];
    char st[100];
    int i, len, n;

    // Get user input
    scanf("%s", ip);

    // Initialize an empty string to store the transformed number
    st[0] = '\0';

    // Check if the input length is not equal to 1
    len = strlen(ip);
    if (len!= 1) {
        // If the first character is '9', keep it and remove it from the input
        if (ip[0] == '9') {
            strcat(st, "9");  // Start the output string with '9'
            memmove(ip, ip + 1, len - 1);  // Remove the first character from the input
        }

        // Iterate through each character in the remaining input
        for (i = 0; i < len; i++) {
            // If the digit is greater than 4, calculate its complement to 9
            if (ip[i] - '0' > 4) {
                n = 9 - (ip[i] - '0');  // Calculate the complement
                strcat(st, &n + '0');  // Append the complement to the output string
            } else {
                // If the digit is 4 or less, keep it unchanged
                strcat(st, &ip[i]);  // Append the original digit to the output string
            }
        }
    } else {
        // If the input length is 1, simply assign it to the output
        strcat(st, ip);
    }

    // Print the final transformed number as an integer
    printf("%d\n", atoi(st));

    return 0;
}
