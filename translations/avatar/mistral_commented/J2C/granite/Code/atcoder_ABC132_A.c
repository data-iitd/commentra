

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    int targ[100] = {0};
    int i, j;
    for (i = 0; i < strlen(s); i++) {
        targ[s[i]]++;
    }
    int flag = 0;
    for (i = 0; i < 100; i++) {
        if (targ[i]!= 2) {
            flag = 1;
            break;
        }
    }
    if (flag == 0 && strlen(s) == 2) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}

