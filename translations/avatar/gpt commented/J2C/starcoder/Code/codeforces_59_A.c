#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char word[100];
    scanf("%s", word);
    
    int uppercase = 0;
    int lowercase = 0;
    
    for (int i = 0; i < strlen(word); i++) {
        char ch = word[i];
        
        if (ch >= 'A' && ch <= 'Z') {
            uppercase++;
        } else {
            lowercase++;
        }
    }
    
    if (uppercase > lowercase) {
        printf("%s\n", word);
    } else if (lowercase > uppercase) {
        printf("%s\n", word);
    } else {
        printf("%s\n", word);
    }
    
    return 0;
}

