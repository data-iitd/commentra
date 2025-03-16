#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500

int main() {
    int n;
    int vec[MAX_N][4];
    int ans = 500;
    int ansprice = 20000;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &vec[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        int flag = 1;

        for (int j = 0; j < n; j++) {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            if (vec[i][3] < ansprice) {
                ansprice = vec[i][3];
                ans = i + 1;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
