
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    char *token = strtok(buf, " ");
    int A = atoi(token);
    token = strtok(NULL, " ");
    int B = atoi(token);

    if ((A + B) % 2 == 0) {
        printf("%d\n", (A + B) / 2);
    } else {
        printf("IMPOSSIBLE\n");
    }

    return 0;
}
