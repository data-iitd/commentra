#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    int dotIndex = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            dotIndex = i;
            break;
        }
    }

    if (str[dotIndex - 1] == '9') {
        printf("GOTO Vasilisa.\n");
    } else if (str[dotIndex + 1] - '0' > 4) {
        char _str[100];
        for (int i = 0; i < dotIndex; i++) {
            _str[i] = str[i];
        }
        _str[dotIndex] = '\0';
        int num = atoi(_str);
        printf("%d\n", num + 1);
    } else {
        for (int i = 0; i < dotIndex; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }

    return 0;
}
