
#include <stdio.h>
#include <string.h>

int main() {
    int N, K;
    char S[100001];
    scanf("%d %d", &N, &K);
    scanf("%s", S);

    int aaaa = 0;
    if (K >= 15 || (1 << K) >= N) {
        aaaa = 1;
    }

    if (aaaa) {
        char min_char = S[0];
        for (int i = 1; i < N; i++) {
            if (S[i] < min_char) {
                min_char = S[i];
            }
        }
        for (int i = 0; i < N; i++) {
            printf("%c", min_char);
        }
        printf("\n");
        return 0;
    }

    char U[200001];
    strcpy(U, S);
    strcat(U, S);

    char min_char = S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] < min_char) {
            min_char = S[i];
        }
    }

    int min_index = 0;
    for (int i = 0; i < N; i++) {
        if (U[i] == min_char) {
            if (check_normal(U, min_index, i)) {
                min_index = i;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%c", U[min_index + i]);
    }
    printf("\n");

    return 0;
}

int check_normal(char *U, int pointer1, int pointer2) {
    for (int i = 0; i < N; i++) {
        if (U[pointer1 + i] > U[pointer2 + i]) {
            return 1;
        } else if (U[pointer1 + i] < U[pointer2 + i]) {
            return 0;
        }
    }
    return 0;
}

