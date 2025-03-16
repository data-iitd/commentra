#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char ans[] = "No";

    scanf("%s", s);

    int cIndex = -1;
    int fIndex = -1;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'C') {
            cIndex = i;
            break;
        }
    }

    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'F') {
            fIndex = i;
            break;
        }
    }

    if (cIndex != -1 && fIndex != -1 && cIndex < fIndex) {
        strcpy(ans, "Yes");
    }

    printf("%s\n", ans);

    return 0;
}
