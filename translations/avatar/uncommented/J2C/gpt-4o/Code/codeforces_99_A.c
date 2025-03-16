#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100]; // Assuming the input will not exceed 99 characters
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
    } else if (atoi(&str[dotIndex + 1]) > 4) {
        char _str[100]; // Buffer to hold the integer part
        strncpy(_str, str, dotIndex);
        _str[dotIndex] = '\0'; // Null-terminate the string
        
        // Convert to integer and add 1
        long long number = atoll(_str) + 1;
        printf("%lld\n", number);
    } else {
        for (int i = 0; i < dotIndex; i++) {
            putchar(str[i]);
        }
        putchar('\n');
    }

    return 0;
}
