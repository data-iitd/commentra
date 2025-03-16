
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char my_str[100] = "";
    fgets(s, sizeof(s), stdin);
    int i = 0;
    while (s[i]!= '\0') {
        if (s[i] == '0' || s[i] == '1') {
            strcat(my_str, &s[i]);
        } else if (s[i] == 'B' && strlen(my_str)!= 0) {
            my_str[strlen(my_str) - 1] = '\0';
        }
        i++;
    }
    printf("%s\n", my_str);
    return 0;
}
