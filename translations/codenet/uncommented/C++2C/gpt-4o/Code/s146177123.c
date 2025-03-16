#include <stdio.h>
#include <stdbool.h>

bool seg[10][7] = {
    {0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 0},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 0, 1, 1, 1, 1},
    {1, 1, 0, 0, 1, 1, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 1},
    {0, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1}
};

int main() {
    int n, t;
    bool st[7];
    
    while (scanf("%d", &n), n != -1) {
        for (int i = 0; i < 7; i++) {
            st[i] = false;
        }
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            char ans[8] = {0};
            
            for (int j = 0; j < 7; j++) {
                ans[j] = (st[j] ^ seg[t][j]) ? '1' : '0';
                st[j] = seg[t][j];
            }
            printf("%s\n", ans);
        }
    }
    
    return 0;
}

// <END-OF-CODE>
