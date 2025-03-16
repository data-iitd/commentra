#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int N, K;
    char S[100001];
    scanf("%d %d", &N, &K);
    scanf("%s", S);

    int aaaaa = 0;

    if (K >= 15) {
        aaaaa = 1;
    } else if (pow(2, K) >= N) {
        aaaaa = 1;
    }

    if (aaaaa) {
        printf("%s%s", S, S);
        return 0;
    }

    char get_last_dict(char* s_str) {
        char U[200002];
        strcpy(U, s_str);
        strcat(U, strrev(s_str));
        char c = *s_str;
        for (int i = 1; i < N; i++) {
            if (s_str[i] < c) {
                c = s_str[i];
            }
        }
        int minindex = 0;
        for (int i = 0; i < N; i++) {
            if (U[i] == c) {
                minindex = i;
                break;
            }
        }
        return strndup(U + minindex, N);
    }

    char* S = get_last_dict(S);

    if (K == 1) {
        printf("%s", S);
    } else {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == S[0]) {
                count++;
            } else {
                break;
            }
        }
        if (count * pow(2, K - 1) >= N) {
            for (int i = 0; i < N; i++) {
                printf("%c", S[0]);
            }
        } else {
            char constructed[100001];
            for (int i = 0; i < count * pow(2, K - 1) - 1; i++) {
                constructed[i] = S[0];
            }
            strcpy(constructed + count * pow(2, K - 1) - 1, S);
            for (int i = 0; i < N; i++) {
                printf("%c", constructed[i]);
            }
        }
    }

    return 0;
}
