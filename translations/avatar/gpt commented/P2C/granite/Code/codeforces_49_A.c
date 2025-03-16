
#include <stdio.h>
#include <string.h>

int main() {
    char a[1000];
    scanf("%s", a);
    int len = strlen(a);
    char vo[] = "aeiouyAEIOUY";
    for (int i = len - 1; i >= 0; i--) {
        if (a[i] =='' || a[i] == '?') {
            continue;
        } else {
            if (strchr(vo, a[i])) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            break;
        }
    }
    return 0;
}
