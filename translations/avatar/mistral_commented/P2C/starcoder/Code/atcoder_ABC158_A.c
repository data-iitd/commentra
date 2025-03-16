#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);
    char result[1000];
    strcpy(result, "Yes");
    if (strstr(s, "A") == NULL || strstr(s, "B") == NULL) {
        strcpy(result, "No");
    }
    printf("%s", result);
    return 0;
}
