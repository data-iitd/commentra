#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char result[100];
    int i = 0;
    int j = 0;

    scanf("%s", s);

    while (i < strlen(s)) {
        if (s[i] == '.') {
            result[j++] = '0';
        } else {
            i++;
            if (s[i] == '.') {
                result[j++] = '1';
            } else {
                result[j++] = '2';
            }
        }
        i++;
    }
    result[j] = '\0';
    printf("%s\n", result);

    return 0;
}
