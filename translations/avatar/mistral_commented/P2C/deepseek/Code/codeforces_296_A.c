#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char m[1000];
    scanf("%s", m);

    int possible = 1;

    for (char i = 'a'; i <= 'z'; i++) {
        int count = 0;
        for (int j = 0; j < strlen(m); j++) {
            if (m[j] == i) {
                count++;
            }
        }
        if (count >= n / 2 + 1) {
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
