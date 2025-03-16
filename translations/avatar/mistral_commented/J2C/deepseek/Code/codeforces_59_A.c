#include <stdio.h>
#include <ctype.h>

int main() {
    char word[100];
    int uppercase = 0, lowercase = 0;

    scanf("%s", word);

    for (int i = 0; word[i] != '\0'; i++) {
        if (isupper(word[i])) {
            uppercase++;
        } else {
            lowercase++;
        }
    }

    if (uppercase > lowercase) {
        for (int i = 0; word[i] != '\0'; i++) {
            printf("%c", toupper(word[i]));
        }
    } else if (lowercase > uppercase) {
        for (int i = 0; word[i] != '\0'; i++) {
            printf("%c", tolower(word[i]));
        }
    } else {
        for (int i = 0; word[i] != '\0'; i++) {
            printf("%c", tolower(word[i]));
        }
    }

    printf("\n");
    return 0;
}
