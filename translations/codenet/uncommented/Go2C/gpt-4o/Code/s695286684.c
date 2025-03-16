#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 100 characters
    scanf("%s", s);
    
    // Replace "2017" with "2018"
    char *pos = strstr(s, "2017");
    if (pos != NULL) {
        strncpy(pos, "2018", 4); // Replace "2017" with "2018"
        // Shift the rest of the string
        memmove(pos + 4, pos + 4, strlen(pos + 4) + 1);
    }
    
    printf("%s\n", s);
    return 0;
}

// <END-OF-CODE>
