#include <stdio.h>
#include <string.h>

int main() {
    char s[100000];
    scanf("%s", s);
    if (strstr(s, "A") && strstr(s, "B")) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}
