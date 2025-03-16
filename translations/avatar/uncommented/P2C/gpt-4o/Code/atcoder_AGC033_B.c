#include <stdio.h>
#include <stdbool.h>

int main() {
    int H, W, N;
    scanf("%d %d %d", &H, &W, &N);
    
    int s_r, s_c;
    scanf("%d %d", &s_r, &s_c);
    
    char S[N + 1], T[N + 1];
    scanf("%s", S);
    scanf("%s", T);
    
    bool Judge = false;
    int S_L = 0, S_R = 0, S_U = 0, S_D = 0;
    int T_L = 0, T_R = 0, T_U = 0, T_D = 0;
    
    for (int x = 0; x < N; x++) {
        if (S[x] == 'L') {
            S_L++;
            if (S_L - T_R - s_c == 0) {
                Judge = true;
            }
        } else if (S[x] == 'R') {
            S_R++;
            if (s_c + (S_R - T_L) == W + 1) {
                Judge = true;
            }
        } else if (S[x] == 'U') {
            S_U++;
            if (S_U - T_D - s_r == 0) {
                Judge = true;
            }
        } else if (S[x] == 'D') {
            S_D++;
            if (s_r + (S_D - T_U) == H + 1) {
                Judge = true;
            }
        }
        
        if (T[x] == 'L') {
            if (S_R - T_L + s_c != 1) {
                T_L++;
            }
        }
        if (T[x] == 'R') {
            if (s_c + (T_R - S_L) != W) {
                T_R++;
            }
        }
        if (T[x] == 'U') {
            if (S_D - T_U + s_r != 1) {
                T_U++;
            }
        }
        if (T[x] == 'D') {
            if (s_r + (T_D - S_U) != H) {
                T_D++;
            }
        }
    }
    
    if (Judge) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    
    return 0;
}

// <END-OF-CODE>
