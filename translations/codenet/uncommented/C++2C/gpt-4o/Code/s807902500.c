#include <stdio.h>
#include <string.h>

int main() {
    char s[100], t[100];
    scanf("%s %s", s, t);
    
    // Concatenate s with itself
    strcat(s, s);
    
    // Check if t is found in the concatenated string s
    if (strstr(s, t) != NULL) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}

// <END-OF-CODE>
