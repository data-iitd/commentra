#include <stdio.h>
#include <string.h>

int main() {
    int H, W, N;
    int s_r, s_c;
    char S[100001], T[100001];
    int S_L = 0, S_R = 0, S_U = 0, S_D = 0;
    int T_L = 0, T_R = 0, T_U = 0, T_D = 0;
    int Judge = 0;

    // Read input
    scanf("%d %d %d", &H, &W, &N);
    scanf("%d %d", &s_r, &s_c);
    scanf("%s", S);
    scanf("%s", T);

    // Process string S
    for (int x = 0; x < N; x++) {
        if (S[x] == 'L') {
            S_L++;
            if (S_L - T_R - s_c == 0) {
                Judge = 1;
            }
        } else if (S[x] == 'R') {
            S_R++;
            if (s_c + (S_R - T_L) == W + 1) {
                Judge = 1;
            }
        } else if (S[x] == 'U') {
            S_U++;
            if (S_U - T_D - s_r == 0) {
                Judge = 1;
            }
        } else if (S[x] == 'D') {
            S_D++;
            if (s_r + (S_D - T_U) == H + 1) {
                Judge = 1;
            }
        }
    }

    // Process string T
    for (int x = 0; x < N; x++) {
        if (T[x] == 'L') {
            if (S_R - T_L + s_c != 1) {
                T_L++;
            }
        } else if (T[x] == 'R') {
            if (s_c + (T_R - S_L) != W) {
                T_R++;
            }
        } else if (T[x] == 'U') {
            if (S_D - T_U + s_r != 1) {
                T_U++;
            }
        } else if (T[x] == 'D') {
            if (s_r + (T_D - S_U) != H) {
                T_D++;
            }
        }
    }

    // Check final condition
    if (Judge) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }

    return 0;
}
