
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char s[100000];
    char t[100000];
    scanf("%s %s", s, t);
    
    int ura = 0;
    int opa = 0;
    
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        if (t[i] == ch) {
            s[i] = 'Я';
            ura++;
        }
    }
    
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        char rch = tolower(ch);
        if (t[i] == rch) {
            s[i] = toupper(ch);
            opa++;
        }
    }
    
    printf("%d %d\n", ura, opa);
    return 0;
}

