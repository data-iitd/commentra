#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Define a character array `s` to store the user input.

    printf("Enter a string: "); // Print a prompt message to the standard output.
    scanf("%s", s); // Read a string input from the standard input and store it in the array `s`.

    // Replace all occurrences of the string "2017" in the array `s` with the string "2018".
    char *pos = strstr(s, "2017");
    while (pos != NULL) {
        memmove(pos + 4, pos + 5, strlen(pos + 5) + 1);
        memmove(pos, "2018", 4);
        pos = strstr(pos, "2017");
    }

    // Print the modified string to the standard output.
    printf("Modified string: %s\n", s);

    return 0;
}
