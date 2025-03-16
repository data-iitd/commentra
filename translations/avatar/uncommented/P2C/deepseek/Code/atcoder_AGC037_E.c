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
    } else if (1 << K >= N) {
        aaaa = 1;
    }
    if (aaaa) {
        printf("%c%d\n", *S < *(S+N-1) ? *S : *(S+N-1), N);
        return 0;
    }

    char* get_last_dict(char* s_str) {
        char U[2*N+1];
        strcpy(U, s_str);
        strcat(U, s_str);
        strrev(U);
        char c = *s_str;
        for (int i = 1; i < N; i++) {
            if (*(s_str+i) < c) {
                c = *(s_str+i);
            }
        }
        int p = strstr(U, c) - U + 1;
        int minindex = p;
        p++;
        while (p < 2*N) {
            if (*(U+p) == c) {
                if (check_normal_dict(U, minindex, p)) {
                    minindex = p;
                }
            }
            p++;
        }
        char* result = (char*)malloc(N+1);
        strncpy(result, U+minindex, N);
        result[N] = '\0';
        return result;
    }

    int check_normal_dict(char* u, int pointer1, int pointer2) {
        for (int i = 0; i < N; i++) {
            if (*(u+pointer1+i) > *(u+pointer2+i)) {
                return 1;
            } else if (*(u+pointer1+i) < *(u+pointer2+i)) {
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
        for (int i = 0; i < N; i++) {
            if (S[i] == S[0]) {
                count++;
            } else {
                break;
            }
        }
        if (count * (1 << (K - 1)) >= N) {
            printf("%c%d\n", S[0], N);
        } else {
            char temp[count * ((1 << (K - 1)) - 1) + N + 1];
            strcpy(temp, S);
            strncpy(temp+count * ((1 << (K - 1)) - 1), S, N);
            temp[count * ((1 << (K - 1)) - 1) + N] = '\0';
            printf("%s\n", temp);
        }
        free(S);
    }
    return 0;
}
