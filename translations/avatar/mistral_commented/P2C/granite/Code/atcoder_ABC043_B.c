
#include <stdio.h>
#include <string.h>

int main() {
    // Ask the user for a string input
    char s[100];
    fgets(s, sizeof(s), stdin);

    // Initialize an empty string variable to store the binary string
    char my_str[100] = "";

    // Iterate through each character in the user input string
    for (int i = 0; i < strlen(s); i++) {
        // If the character is '0' or '1', append it to the binary string
        if (s[i] == '0' || s[i] == '1') {
            strcat(my_str, &s[i]);
        }
        // If the character is 'B', remove the last character from the binary string before 'B' was encountered
        else if (s[i] == 'B' && strlen(my_str)!= 0) {
            my_str[strlen(my_str)-1] = '\0';
        }
    }

    // Print the final binary string
    printf("%s\n", my_str);

    return 0;
}
