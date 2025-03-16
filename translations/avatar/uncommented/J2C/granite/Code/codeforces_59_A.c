
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[100];
    scanf("%s", word);
    int uppercase = 0;
    int lowercase = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isupper(word[i])) {
            uppercase++;
        } else {
            lowercase++;
        }
    }
    if (uppercase > lowercase) {
        printf("%s\n", strupr(word));
    } else if (lowercase > uppercase) {
        printf("%s\n", strlwr(word));
    } else {
        printf("%s\n", strlwr(word));
    }
    return 0;
}
//END-OF-CODE