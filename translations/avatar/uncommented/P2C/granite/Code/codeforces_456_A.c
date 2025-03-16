
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int m[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[i][1] < m[j][1]) {
                int temp = m[i][0];
                m[i][0] = m[j][0];
                m[j][0] = temp;
                temp = m[i][1];
                m[i][1] = m[j][1];
                m[j][1] = temp;
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
        if (m[i][1] >= m[i + 1][1]) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("Happy Alex\n");
    } else {
        printf("Poor Alex\n");
    }
    return 0;
}
