#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];  // Buffer to hold the input
    scanf("%s", input);  // Taking an input from the user

    // Splitting the input into two parts using '.' as the delimiter
    char *l1 = strtok(input, ".");  // First part
    char *l2 = strtok(NULL, ".");    // Second part

    // Converting the first part into a string
    char s[100];
    strcpy(s, l1);

    // Converting the second part into an integer
    int i = l2[0] - '0';  // Assuming the first character of the second part is a digit

    // Checking if the last character of the first part is '9'
    if (s[strlen(s) - 1] == '9') {
        printf("GOTO Vasilisa.\n");  // Printing "GOTO Vasilisa." if the last character is '9'
    }
    // Checking if the last character of the first part is not '9' and the integer from the second part is less than 5
    else if (s[strlen(s) - 1] != '9' && i < 5) {
        printf("%s\n", s);  // Printing the first part
    }
    // If the last character of the first part is not '9' and the integer from the second part is 5 or more
    else {
        int num = atoi(s);  // Convert the first part to an integer
        num += 1;           // Increment the number by 1
        printf("%d\n", num);  // Printing the incremented number
    }

    return 0;
}

// <END-OF-CODE>
