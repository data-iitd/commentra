
#include <stdio.h>
#include <string.h>

int main() {
    char S[100];
    scanf("%s", S);
    for (int i = 2; i <= strlen(S); i = i + 2) {
        if (strstr(S, S + (strlen(S) - i) / 2) == S + (strlen(S) - i) / 2) {
            printf("%d\n", strlen(S) - i);
            break;
        }
    }
    return 0;
}
