

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    // Read input string from the user
    char str[1000];
    fgets(str, sizeof(str), stdin);

    // Find the index of the dot ('.') in the string
    int dotIndex = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            dotIndex = i;
            break;
        }
    }

    // Check if the character before the dot is '9'
    if (str[dotIndex - 1] == '9') {
        printf("GOTO Vasilisa.\n");
    }
    // If the character before the dot is not '9', check the digit after the dot
    else if (str[dotIndex + 1] - '0' > 4) {
        // Increment the number before the dot by 1 and print the result
        char _str[1000];
        strncpy(_str, str, dotIndex);
        _str[dotIndex] = '\0';
        printf("%s\n", (char *) (strtod(_str, NULL) + 1));
    }
    // If the digit after the dot is 4 or less, print the number before the dot without any changes
    else {
        printf("%s\n", str);
    }

    return 0;
}
