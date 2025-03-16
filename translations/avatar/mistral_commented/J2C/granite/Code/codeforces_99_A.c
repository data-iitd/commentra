

#include <stdio.h>
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
        strncpy(_str, str, dotIndex);
        _str[dotIndex] = '\0';
        printf("%s\n", strtoull(_str, NULL, 10) + 1);
    } else {
        printf("%s", str);
    }
    return 0;
}
