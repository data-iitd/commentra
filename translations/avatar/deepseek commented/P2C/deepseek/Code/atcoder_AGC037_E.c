#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N+1];
    scanf("%s", S);
    int aaaa = 0;
    if (K >= 15) {
        aaaa = 1;
    } else if (pow(2, K) >= N) {
        aaaa = 1;
    }
    if (aaaa) {
        printf("%c%d\n", *S, N);
        return 0;
    }

    char* get_last_dict(char* s_str) {
        int len = strlen(s_str);
        char* U = (char*)malloc(2*len+1);
        strcpy(U, s_str);
        strcat(U, strrev(s_str));
        char c = *S;
        int p = strpos(U, c);
        int minindex = p;
        p += 1;
        while (p < 2*len) {
            if (U[p] == c) {
                if (check_normal_dict(U, minindex, p)) {
                    minindex = p;
                }
            }
            p += 1;
        }
        char* result = (char*)malloc(N+1);
        strncpy(result, U+minindex, N);
        result[N] = '\0';
        free(U);
        return result;
    }

    int check_normal_dict(char* u, int pointer1, int pointer2) {
        for (int i = 0; i < N; i++) {
            if (u[pointer1 + i] > u[pointer2 + i]) {
                return 1;
            } else if (u[pointer1 + i] < u[pointer2 + i]) {
                return 0;
            }
        }
        return 0;
    }

    char* S = get_last_dict(S);
    if (K == 1) {
        printf("%s\n", S);
    } else {
        int count = 0;
        for (int i = 0; i < strlen(S); i++) {
            if (S[i] == S[0]) {
                count += 1;
            } else {
                break;
            }
        }
        if (count * (pow(2, K-1)) >= N) {
            char result[N+1];
            memset(result, S[0], N);
            result[N] = '\0';
            printf("%s\n", result);
        } else {
            char* new_S = (char*)malloc(count * (pow(2, K-1)) + strlen(S) + 1);
            memset(new_S, S[0], count * (pow(2, K-1)));
            strcpy(new_S + count * (pow(2, K-1)), S);
            printf("%s\n", new_S);
            free(new_S);
        }
    }

    return 0;
}
