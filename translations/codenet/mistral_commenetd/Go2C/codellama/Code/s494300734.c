#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char ans[100] = "No";
    scanf("%s", s);

    if (strstr(s, "C") < strstr(s, "F")) {
        strcpy(ans, "Yes");
    }

    if (strstr(s, "C") < 0) {
        // Do nothing
    }

    printf("%s\n", ans);

    return 0;
}

