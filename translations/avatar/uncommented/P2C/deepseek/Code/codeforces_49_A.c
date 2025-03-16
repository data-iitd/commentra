#include <stdio.h>
#include <string.h>

int main() {
    char a[1000];
    char vo[] = "aeiouyAEIOUY";
    fgets(a, sizeof(a), stdin);
    int len = strlen(a);
    for (int i = len - 1; i >= 0; i--) {
        if (a[i] == ' ' || a[i] == '?' || a[i] == '\n') {
            continue;
        } else {
            if (strchr(vo, a[i]) != NULL) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            break;
        }
    }
    return 0;
}
