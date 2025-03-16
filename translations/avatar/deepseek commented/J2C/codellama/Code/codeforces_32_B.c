#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char n[100];
    bool s = false;
    scanf("%s", n);

    for (int i = 0; i < strlen(n); i++) {
        if (n[i] == '.') {
            if (s) {
                printf("1");
                s = false;
            } else {
                printf("0");
                s = false;
            }
        } else {
            if (s) {
                printf("2");
                s = false;
            } else {
                s = true;
            }
        }
    }
    return 0;
}

