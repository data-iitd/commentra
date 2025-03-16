#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 100000

int N, K;
char S[MAX_N + 1];

int check_normal_dict(char *u, int pointer1, int pointer2) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return 1; // True
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return 0; // False
        }
    }
    return 0; // False
}

char* get_last_dict(char *s_str) {
    static char U[MAX_N * 2 + 1];
    strcpy(U, s_str);
    strcat(U, s_str);
    
    char c = s_str[0];
    int p = 0;
    while (s_str[p] != '\0') {
        if (s_str[p] == c) {
            break;
        }
        p++;
    }
    int minindex = p;
    p++;
    
    while (p < strlen(U)) {
        if (U[p] == c) {
            if (check_normal_dict(U, minindex, p)) {
                minindex = p;
            }
        }
        p++;
    }
    
    char *result = (char *)malloc(N + 1);
    strncpy(result, U + minindex, N);
    result[N] = '\0';
    return result;
}

int main() {
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    
    int aaaa = 0;
    if (K >= 15) {
        aaaa = 1;
    } else if ((1 << K) >= N) {
        aaaa = 1;
    }
    
    if (aaaa) {
        for (int i = 0; i < N; i++) {
            putchar(min(S[i], S[0]));
        }
        putchar('\n');
        return 0;
    }
    
    char *result = get_last_dict(S);
    
    if (K == 1) {
        printf("%s\n", result);
    } else {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (result[i] == result[0]) {
                count++;
            } else {
                break;
            }
        }
        
        if (count * (1 << (K - 1)) >= N) {
            for (int i = 0; i < N; i++) {
                putchar(result[0]);
            }
            putchar('\n');
        } else {
            for (int i = 0; i < count * ((1 << (K - 1)) - 1); i++) {
                putchar(result[0]);
            }
            printf("%s\n", result);
        }
    }
    
    free(result);
    return 0;
}

// <END-OF-CODE>
