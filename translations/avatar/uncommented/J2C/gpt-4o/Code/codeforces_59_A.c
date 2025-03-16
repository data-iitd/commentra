#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char word[100]; // Assuming the maximum length of the word is 99 characters
    scanf("%s", word);
    
    int uppercase = 0;
    int lowercase = 0;
    
    for (int i = 0; i < strlen(word); i++) {
        char ch = word[i];
        if (isupper(ch)) {
            uppercase++;
        } else {
            lowercase++;
        }
    }
    
    if (uppercase > lowercase) {
        for (int i = 0; i < strlen(word); i++) {
            putchar(toupper(word[i]));
        }
    } else {
        for (int i = 0; i < strlen(word); i++) {
            putchar(tolower(word[i]));
        }
    }
    
    putchar('\n'); // Print a newline at the end
    return 0;
}

// <END-OF-CODE>
