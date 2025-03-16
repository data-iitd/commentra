#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool debug = false;

void log_message(const char *text) {
    if (debug) {
        printf("%s\n", text);
    }
}

char parse_input(char *c) {
    if (fgets(c, 2, stdin) == NULL) {
        return '\0'; // Handle input error
    }
    return c[0];
}

char solve(char c) {
    const char *a = "abcdefghijklmnopqrstuvwxyz";
    char *pos = strchr(a, c);
    if (pos != NULL && *(pos + 1) != '\0') {
        return *(pos + 1);
    }
    return '\0'; // Handle case where c is 'z'
}

int main() {
    char c[2]; // To hold the input character and null terminator
    c[1] = '\0'; // Null terminate the string
    c[0] = parse_input(c);
    
    char result = solve(c[0]);
    
    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("No next character\n");
    }
    
    return 0;
}

// <END-OF-CODE>
