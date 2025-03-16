#include <stdio.h>
#include <string.h>

int main() {
    int K;
    char S[100];
    scanf("%d", &K);
    scanf("%s", S);
    if (strlen(S) <= K) {
        printf("%s\n", S);
    } else {
        char result[100];
        strncpy(result, S, K);
        result[K] = '\0';
        printf("%s...\n", result);
    }
    return 0;
}
