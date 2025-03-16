
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char str[1000];
    scanf("%s", str);
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
        for (int i = 0; i < dotIndex; i++) {
            _str[i] = str[i];
        }
        printf("%d\n", atoi(_str) + 1);
    } else {
        for (int i = 0; i < dotIndex; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}
// END-OF-CODE