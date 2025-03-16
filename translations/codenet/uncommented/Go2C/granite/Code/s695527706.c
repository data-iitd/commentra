
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100];
    scanf("%d %s", &n, s);
    printf("%d\n", (int)strstr(s, "ABC") - s + 1);
    return 0;
}
// 