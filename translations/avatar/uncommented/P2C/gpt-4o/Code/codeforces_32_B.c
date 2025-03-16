#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);
    char result[100] = ""; // To store the result
    int i = 0;

    while (i < strlen(s)) {
        if (s[i] == '.') {
            strcat(result, "0");
        } else {
            i++;
            if (s[i] == '.') {
                strcat(result, "1");
            } else {
                strcat(result, "2");
            }
        }
        i++;
    }
    printf("%s\n", result);
    return 0;
}

// <END-OF-CODE>
