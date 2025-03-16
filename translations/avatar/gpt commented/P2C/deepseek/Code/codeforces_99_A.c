#include <stdio.h>
#include <string.h>

int main() {
    char l[100];
    char *s, *p;
    int i;

    // Read input from the user
    fgets(l, sizeof(l), stdin);

    // Remove newline character if present
    l[strcspn(l, "\n")] = '\0';

    // Split the input string into two parts using '.' as the delimiter
    s = strtok(l, ".");
    p = strtok(NULL, ".");

    // Convert the first part of the input into a list of characters
    int len = strlen(s);
    char s_list[len + 1];
    strcpy(s_list, s);

    // Convert the second part of the input into a list of characters
    char p_list[2];
    strncpy(p_list, p, 1);
    p_list[1] = '\0';

    // Extract the first character from the second part and convert it to an integer
    i = atoi(p_list);

    // Check if the last character of the first part is '9'
    if (s_list[len - 1] == '9') {
        // If it is '9', print the message "GOTO Vasilisa."
        printf("GOTO Vasilisa.\n");
    // Check if the last character is not '9' and the integer i is less than 5
    } else if (s_list[len - 1] != '9' && i < 5) {
        // If both conditions are true, join the list of characters into a string and print it
        printf("%s\n", s_list);
    } else {
        // If the last character is not '9' and i is 5 or more
        // Join the list of characters into a string, convert it to an integer, increment it by 1, and convert it back to a string
        int num = atoi(s_list) + 1;
        printf("%d\n", num);
    }

    return 0;
}
