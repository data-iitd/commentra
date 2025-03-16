#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    if (strchr(s, 'A') && strchr(s, 'B')) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
