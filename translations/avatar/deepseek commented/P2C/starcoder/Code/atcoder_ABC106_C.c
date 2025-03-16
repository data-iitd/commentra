#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[100000];
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    int l = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i]!= '1') {
            break;
        }
        l++;
    }
    if (l >= k) {
        printf("1");
    } else {
        printf("%c", s[l]);
    }
    return 0;
}

