#include <stdio.h>
#include <ctype.h>

int main() {
    char txt[1000];
    int cu = 0, cl = 0;
    
    scanf("%s", txt);
    
    for (int i = 0; txt[i] != '\0'; i++) {
        if (islower(txt[i])) {
            cl++;
        } else {
            cu++;
        }
    }
    
    if (cu > cl) {
        for (int i = 0; txt[i] != '\0'; i++) {
            printf("%c", toupper(txt[i]));
        }
    } else {
        for (int i = 0; txt[i] != '\0'; i++) {
            printf("%c", tolower(txt[i]));
        }
    }
    
    printf("\n");
    return 0;
}
