
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    int length = strlen(s);
    char ch = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (s[i]!='' && s[i]!= '?') {
            ch = s[i];
            break;
        }
    }
    ch = tolower(ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
//END-OF-CODE