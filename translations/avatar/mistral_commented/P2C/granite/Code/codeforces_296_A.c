
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char m[1000];
    scanf("%d", &n);
    scanf("%s", m);
    int possible = 1;
    for (int i = 0; i < strlen(m); i++) {
        int count = 0;
        for (int j = 0; j < strlen(m); j++) {
            if (m[i] == m[j]) {
                count++;
            }
        }
        if (count >= (n / 2 + 1)) {
            possible = 0;
            break;
        }
    }
    if (possible) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
