#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);
    int i = 0;
    char result[1000];
    while (i < strlen(s)) {
        if (s[i] == '.') {
            strcat(result, "0");
        } else {
            i++;
            if (s[i] == '.') {
                strcat(result, "1");
            } else {
                strcat(result, "2");
            }
        }
        i++;
    }
    printf("%s", result);
    return 0;
}
