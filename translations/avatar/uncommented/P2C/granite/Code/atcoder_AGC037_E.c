
#include <stdio.h>
#include <string.h>

int main() {
    int N, K;
    char S[100001];
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    int aaaa = 0;
    if (K >= 15) {
        aaaa = 1;
    } else if (1 << K >= N) {
        aaaa = 1;
    }
    if (aaaa) {
        printf("%c", *min(S, S + N));
        for (int i = 1; i < N; i++) {
            printf("%c", *min(S, S + N));
        }
        printf("\n");
        return 0;
    }
    char U[200001];
    for (int i = 0; i < N; i++) {
        U[i] = S[i];
        U[N + i] = S[N - 1 - i];
    }
    char c = *min(S, S + N);
    int p = 0;
    while (p < N) {
        if (U[p] == c) {
            if (check_normal_dict(U, p, N + p)) {
                p = N + p;
            }
        }
        p++;
    }
    for (int i = 0; i < N; i++) {
        S[i] = U[p - N + i];
    }
    if (K == 1) {
        printf("%s\n", S);
    } else {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == S[0]) {
                count++;
            } else {
                break;
            }
        }
        if (count * (1 << (K - 1)) >= N) {
            printf("%c", S[0]);
            for (int i = 1; i < N; i++) {
                printf("%c", S[0]);
            }
            printf("\n");
        } else {
            for (int i = 0; i < N; i++) {
                S[i] = S[0];
            }
            for (int i = 0; i < (count * ((1 << (K - 1)) - 1)); i++) {
                S[i] = S[i % N];
            }
            printf("%s\n", S);
        }
    }
    return 0;
}

int check_normal_dict(char *u, int pointer1, int pointer2) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return 1;
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return 0;
        }
    }
    return 0;
}

// END-OF-CODE