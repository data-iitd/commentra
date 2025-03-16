#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replace(char *str, const char *old, const char *new) {
    char *pos, temp[1000];
    int index = 0;
    int oldlen = strlen(old);
    int newlen = strlen(new);

    while ((pos = strstr(str, old)) != NULL) {
        // Copy characters from the beginning of str to the position of old
        strncpy(temp, str, pos - str);
        temp[pos - str] = '\0';

        // Concatenate new string
        strcat(temp, new);
        
        // Concatenate the remaining part of str after old
        strcat(temp, pos + oldlen);

        // Copy temp back to str
        strcpy(str, temp);
    }
}

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Remove newline character

    replace(s, "dream", "D");
    replace(s, "erase", "E");
    replace(s, "Der", "");
    replace(s, "Er", "");
    replace(s, "D", "");
    replace(s, "E", "");
    
    // Trim spaces (if any)
    char *end;
    while (isspace((unsigned char)*s)) s++;
    end = s + strlen(s) - 1;
    while (end > s && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    if (strlen(s) == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
