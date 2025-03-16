
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100000];
    scanf("%s", s);
    if (strstr(s, "A") && strstr(s, "B")) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

