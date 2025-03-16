#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    int dotIndex = -1;

    // Find the index of the decimal point in the input
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            dotIndex = i;
            break;
        }
    }

    // Check if the digit before the decimal point is '9'
    if (str[dotIndex - 1] == '9') {
        // If it is, print a specific message
        printf("GOTO Vasilisa.\n");
    }
    // Check if the digit after the decimal point is greater than 4
    else if (str[dotIndex + 1] - '0' > 4) {
        // If it is, create a new string from the integer part and add 1
        char _str[100];
        int j = 0;
        for (int i = 0; i < dotIndex; i++)
            _str[j++] = str[i];
        _str[j] = '\0';

        // Increment the integer part
        int len = strlen(_str);
        int carry = 1;
        for (int i = len - 1; i >= 0; i--) {
            int digit = _str[i] - '0' + carry;
            _str[i] = (digit % 10) + '0';
            carry = digit / 10;
        }

        // Print the incremented value
        if (carry > 0) {
            printf("%d", carry);
        }
        printf("%s\n", _str);
    }
    // If the digit after the decimal point is 4 or less
    else {
        // Print the integer part as it is
        for (int i = 0; i < dotIndex; i++)
            printf("%c", str[i]);
        printf("\n");
    }

    return 0;
}
