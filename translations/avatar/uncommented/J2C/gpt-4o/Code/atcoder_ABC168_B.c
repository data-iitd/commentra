#include <stdio.h>
#include <string.h>

int main() {
    int K;
    scanf("%d", &K);
    
    char S[100]; // Assuming the maximum length of S is 99 characters
    scanf("%s", S);
    
    if (strlen(S) <= K) {
        printf("%s\n", S);
    } else {
        for (int i = 0; i < K; i++) {
            putchar(S[i]);
        }
        printf("...\n");
    }
    
    return 0;
}
