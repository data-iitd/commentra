#include <stdio.h>
#include <string.h>

int main() {
    int K;
    char S[1000];

    scanf("%d", &K);
    scanf("%s", S);

    if (strlen(S) <= K) {
        printf("%s\n", S);
    } else {
        char result[K + 4]; // K characters + "..." = K + 4 characters
        strncpy(result, S, K);
        result[K] = '\0';
        strcat(result, "...");
        printf("%s\n", result);
    }

    return 0;
}

