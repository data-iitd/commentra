
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);

    int dt[256] = {0};
    int i;
    for (i = 0; s[i]!= '\0'; i++) {
        dt[s[i]]++;
    }

    int cnt = 0;
    int x = 1;
    for (i = 0; i < 256; i++) {
        if (dt[i] % 2!= 0 && cnt < 1) {
            cnt++;
        } else if (dt[i] % 2!= 0 && cnt >= 1) {
            x = 0;
            break;
        }
    }

    if (x) {
        printf("First\n");
    } else if (!x && strlen(s) % 2 == 0) {
        printf("Second\n");
    } else if (!x && strlen(s) % 2!= 0) {
        printf("First\n");
    }

    return 0;
}
