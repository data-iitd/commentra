#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char my_str[100] = "";
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '0' || c == '1') {
            strncat(my_str, &c, 1);
        } else if (c == 'B' && strlen(my_str) != 0) {
            my_str[strlen(my_str) - 1] = '\0';
        }
    }
    printf("%s\n", my_str);
    return 0;
}
