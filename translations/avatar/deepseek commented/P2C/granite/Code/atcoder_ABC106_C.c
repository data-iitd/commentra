
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    int k;
    scanf("%s %d", s, &k);
    int l = 0;
    while (s[l] == '1' && l < strlen(s)) {
        l++;
    }
    if (l >= k) {
        printf("1\n");
    } else {
        printf("%c\n", s[l]);
    }
    return 0;
}
// END-OF-CODE