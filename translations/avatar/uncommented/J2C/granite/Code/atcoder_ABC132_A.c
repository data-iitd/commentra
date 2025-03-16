
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100];
    scanf("%s", s);
    int targ[256] = {0};
    int i;
    for (i = 0; i < strlen(s); i++) {
        targ[s[i]]++;
    }
    int ok = 1;
    for (i = 0; i < 256; i++) {
        if (targ[i]!= 2) {
            ok = 0;
            break;
        }
    }
    if (ok && sizeof(targ) / sizeof(int) == 2) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
