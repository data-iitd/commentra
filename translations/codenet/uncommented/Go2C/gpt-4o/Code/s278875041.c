#include <stdio.h>
#include <string.h>

void replace_char(char *str, char old_char, char new_char) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
    }
}

int main() {
    char a[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", a);

    replace_char(a, '1', '0');
    replace_char(a, '9', '1');
    replace_char(a, '0', '9');

    printf("%s\n", a);
    return 0;
}

// <END-OF-CODE>
