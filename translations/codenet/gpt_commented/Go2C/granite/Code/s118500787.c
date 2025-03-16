
#include <stdio.h>

int main() {
    char S[100001], T[100001];
    scanf("%s %s", S, T);

    int max = 0;
    for (int i = 0; i <= strlen(S) - strlen(T); i++) {
        int c = 0;
        for (int j = 0; j < strlen(T); j++) {
            if (S[i + j] == T[j]) {
                c++;
            }
        }
        if (max < c) {
            max = c;
        }
    }

    printf("%d\n", strlen(T) - max);

    return 0;
}
