#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);
    
    if (strlen(s) >= 4 && strncmp(s, "YAKI", 4) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}

// <END-OF-CODE>
