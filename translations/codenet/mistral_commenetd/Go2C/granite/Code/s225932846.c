

#include <stdio.h>
#include <string.h>

int main() {
    char S[100];
    scanf("%s", S);

    int i = 2;
    while (i <= strlen(S)) {
        if (strncmp(S, S + (strlen(S) - i) / 2, (strlen(S) - i) / 2) == 0) {
            printf("%d\n", strlen(S) - i);
            break;
        }
        i += 2;
    }

    return 0;
}
