

#include <stdio.h>
#include <string.h>

int main() {
    char l[100];
    char s[100];
    char p[100];
    int i;

    scanf("%s", l);  // Taking an input from the user
    sscanf(l, "%[^.]", s);  // Splitting the input into a list of strings separated by a period (.)
    sscanf(l, "%*[^.].%s", p);  // Splitting the input into a list of strings separated by a period (.)
    i = atoi(p);  // Converting the second part of the split input into an integer

    // Checking if the last character of the first part is '9'
    if (s[strlen(s) - 1] == '9') {
        printf("GOTO Vasilisa.\n");  // Printing "GOTO Vasilisa." if the last character is '9'
    }

    // Checking if the last character of the first part is not '9' and the integer from the second part is less than 5
    else if (s[strlen(s) - 1]!= '9' && i < 5) {
        printf("%s\n", s);  // Printing the first part
    }

    // If the last character of the first part is not '9' and the integer from the second part is 5 or more
    else {
        s[strlen(s) - 1]++;  // Incrementing the last character of the first part
        printf("%s\n", s);  // Printing the incremented first part
    }

    return 0;
}

