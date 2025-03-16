
#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    scanf("%s", a);
    char tmp[100];
    strcpy(tmp, a);
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '1') {
            tmp[i] = '0';
        }
    }
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '9') {
            tmp[i] = '1';
        }
    }
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '0') {
            tmp[i] = '9';
        }
    }
    printf("%s\n", tmp);
    return 0;
}
