#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char result[4];

    // Read a line from the standard input
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = '\0';

    // Initialize the variable result with "Yes" if "A" and "B" are present in s, otherwise initialize it with "No"
    if (strstr(s, "A") != NULL && strstr(s, "B") != NULL) {
        strcpy(result, "Yes");
    } else {
        strcpy(result, "No");
    }

    // Print the value of the variable result
    printf("%s\n", result);

    return 0;
}
