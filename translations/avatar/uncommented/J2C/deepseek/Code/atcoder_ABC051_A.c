#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[1000];
    fgets(a, sizeof(a), stdin);
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == ',') {
            a[i] = ' ';
        }
    }
    printf("%s", a);
    return 0;
}
