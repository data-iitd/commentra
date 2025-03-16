#include <stdio.h>
#include <string.h>

int main() {
    char S[100001];
    scanf("%s", S);
    int len = strlen(S);
    for (int i = 2; i <= len; i = i + 2) {
        if (strncmp(S, S + (len - i) / 2, (len - i) / 2) == 0) {
            printf("%d\n", len - i);
            break;
        }
    }
    return 0;
}
