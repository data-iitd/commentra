#include <stdio.h>
#include <string.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    char ans[10];
    if (a == 1 || b == 1) {
        if (a == 1 && b == 1) {
            strcpy(ans, "Draw");
        } else if (a == 1) {
            strcpy(ans, "Alice");
        } else {
            strcpy(ans, "Bob");
        }
    } else {
        if (a == b) {
            strcpy(ans, "Draw");
        } else if (a > b) {
            strcpy(ans, "Alice");
        } else {
            strcpy(ans, "Bob");
        }
    }
    printf("%s\n", ans);
    return 0;
}
