#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100]; // Buffer to hold the input
    fgets(input, sizeof(input), stdin); // Read input from the user

    // Split the input string into two parts using '.' as the delimiter
    char *l = strtok(input, ".");
    char *p = strtok(NULL, ".");

    // Convert the first part of the input into a string
    char s[100];
    strcpy(s, l);

    // Extract the first character from the second part and convert it to an integer
    int i = p[0] - '0'; // Convert char to int

    // Check if the last character of the first part is '9'
    if (s[strlen(s) - 1] == '9') {
        // If it is '9', print the message "GOTO Vasilisa."
        printf("GOTO Vasilisa.\n");
    }
    // Check if the last character is not '9' and the integer i is less than 5
    else if (s[strlen(s) - 1] != '9' && i < 5) {
        // If both conditions are true, print the string
        printf("%s\n", s);
    } else {
        // If the last character is not '9' and i is 5 or more
        // Convert the string to an integer, increment it by 1, and convert it back to a string
        int num = atoi(s);
        num += 1;
        printf("%d\n", num); // Print the incremented value
    }

    return 0;
}

// <END-OF-CODE>
