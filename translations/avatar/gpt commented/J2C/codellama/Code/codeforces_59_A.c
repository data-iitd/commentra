#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[100];
    int uppercase = 0, lowercase = 0;
    int i;
    
    printf("Enter a word: ");
    scanf("%s", word);
    
    for (i = 0; i < strlen(word); i++) {
        if (isupper(word[i])) {
            uppercase++;
        } else {
            lowercase++;
        }
    }
    
    if (uppercase > lowercase) {
        printf("%s\n", toupper(word));
    } else if (lowercase > uppercase) {
        printf("%s\n", tolower(word));
    } else {
        printf("%s\n", tolower(word));
    }
    
    return 0;
}

