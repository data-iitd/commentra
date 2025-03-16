#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S[1000];
    scanf("%s", S);

    if (strncmp(S, "YAKI", 4) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
