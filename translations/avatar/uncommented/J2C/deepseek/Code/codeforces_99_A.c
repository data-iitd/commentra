#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);
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
        char _str[1000];
        int j = 0;
        for (int i = 0; i < dotIndex; i++) {
            _str[j++] = str[i];
        }
        _str[j] = '\0';
        int num = atoi(_str) + 1;
        printf("%d\n", num);
    } else {
        for (int i = 0; i < dotIndex; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}
