
#include <stdio.h>
#include <string.h>

int main() {
    char stdin[1000];
    scanf("%s", stdin);
    char s[1000];
    strcpy(s, stdin);

    // Check if the string s contains both "A" and "B"
    if (strstr(s, "A") && strstr(s, "B")) {
        char result[1000] = "Yes";
    } else {
        char result[1000] = "No";
    }

    printf("%s", result);
    return 0;
}
