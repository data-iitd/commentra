
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char m[100000];
    scanf("%s", m);
    int possible = 1;
    for (int i = 0; i < strlen(m); i++) {
        int count = 0;
        for (int j = 0; j < strlen(m); j++) {
            if (m[i] == m[j]) {
                count++;
            }
        }
        if (count >= n / 2 + 1) {
            possible = 0;
            break;
        }
    }
    printf("%s\n", possible? "YES" : "NO");
    return 0;
}

