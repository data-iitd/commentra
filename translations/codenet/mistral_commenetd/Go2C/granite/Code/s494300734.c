
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    char ans[4] = "No";

    if (strstr(s, "C")!= NULL && strstr(s, "F")!= NULL) {
        if (strstr(s, "C") < strstr(s, "F")) {
            strcpy(ans, "Yes");
        }
    }

    printf("%s\n", ans);

    return 0;
}

// END-OF-CODE