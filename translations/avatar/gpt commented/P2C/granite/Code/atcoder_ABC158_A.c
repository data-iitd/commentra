
#include <stdio.h>

int main() {
    // Read input from the standard input (user input)
    char s[100];
    fgets(s, 100, stdin);

    // Check if both 'A' and 'B' are present in the input string
    // If both are found, set result to "Yes", otherwise set it to "No"
    char result[5];
    if (strstr(s, "A")!= NULL && strstr(s, "B")!= NULL) {
        strcpy(result, "Yes");
    } else {
        strcpy(result, "No");
    }

    // Print the result indicating whether both 'A' and 'B' were found
    printf("%s\n", result);

    return 0;
}
