#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char word[100];
    scanf("%s", word);
    int uppercase = 0, lowercase = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isupper(word[i])) {
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

