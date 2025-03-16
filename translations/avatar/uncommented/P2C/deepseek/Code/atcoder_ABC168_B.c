#include <stdio.h>
#include <string.h>

int main() {
    int K;
    char S[1000];

    scanf("%d", &K);
    scanf("%s", S);

    int len = strlen(S);
    if (len <= K) {
        printf("%s", S);
    } else {
        for (int i = 0; i < K; i++) {
            printf("%c", S[i]);
        }
        printf("...");
    }

    return 0;
}
