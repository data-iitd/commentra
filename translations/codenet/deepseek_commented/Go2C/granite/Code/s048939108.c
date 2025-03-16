

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buf[1000];
    fgets(buf, sizeof(buf), stdin);
    char *s = buf;
    if (strstr(s, "YAKI") == s) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

