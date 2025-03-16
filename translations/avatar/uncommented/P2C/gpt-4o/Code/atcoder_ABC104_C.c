#include <stdio.h>
#include <stdlib.h>

int main() {
    int D, G;
    scanf("%d %d", &D, &G);
    
    int PC[D][2];
    for (int i = 0; i < D; i++) {
        scanf("%d %d", &PC[i][0], &PC[i][1]);
    }
    
    int ans = 1000000000; // 10 ** 9
    for (int i = 0; i < (1 << D); i++) {
        int score = 0;
        int problem = 0;
        
        for (int j = 0; j < D; j++) {
            if ((i >> j) & 1) {
                score += 100 * (j + 1) * PC[j][0] + PC[j][1];
                problem += PC[j][0];
            }
        }
        
        if (score > G) {
            continue;
        }
        
        int left = G - score;
        for (int j = 0; j < D; j++) {
            if ((i >> j) & 1) {
                continue;
            }
            if (left > 100 * (j + 1) * PC[j][0] + PC[j][1]) {
                continue;
            } else {
                int tmp = (left + (100 * (j + 1)) - 1) / (100 * (j + 1));
                if (tmp > PC[j][0]) {
                    tmp = PC[j][0];
                }
                ans = (ans < problem + tmp) ? ans : (problem + tmp);
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
