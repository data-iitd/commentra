
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

    char b[100];
    strcpy(b, tmp);
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] == '9') {
            b[i] = '1';
        }
    }

    char ans[100];
    strcpy(ans, b);
    for (int i = 0; i < strlen(ans); i++) {
        if (ans[i] == '0') {
            ans[i] = '9';
        }
    }

    printf("%s\n", ans);

    return 0;
}

// Printing the final answer