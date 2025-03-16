#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char m[1000];
    scanf("%s", m);
    int possible = 1;
    int count[256] = {0};
    for (int i = 0; m[i] != '\0'; i++) {
        count[(unsigned char)m[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] >= n / 2 + 1) {
            possible = 0;
            break;
        }
    }
    printf("%s\n", possible ? "YES" : "NO");
    return 0;
}
