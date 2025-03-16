#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[1001];
    scanf("%s", S);
    int len = strlen(S);
    int count[256] = {0};
    for (int i = 0; i < len; i++) {
        count[(unsigned char)S[i]]++;
    }
    int unique_chars = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            unique_chars++;
        }
    }
    if (unique_chars != 2) {
        printf("No\n");
        return 0;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] != 2) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
