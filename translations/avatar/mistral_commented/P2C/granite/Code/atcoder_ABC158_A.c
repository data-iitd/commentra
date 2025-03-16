
#include <stdio.h>

int main() {
    // Read a line from the standard input
    char s[100];
    fgets(s, 100, stdin);

    // Initialize the variable result with "Yes" if "A" and "B" are present in s, otherwise initialize it with "No"
    char result[10];
    if (strstr(s, "A")!= NULL && strstr(s, "B")!= NULL) {
        strcpy(result, "Yes");
    } else {
        strcpy(result, "No");
    }

    // Print the value of the variable result
    printf("%s\n", result);

    return 0;
}
// END-OF-CODE