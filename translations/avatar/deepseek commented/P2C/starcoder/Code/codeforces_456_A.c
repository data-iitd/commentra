
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int m[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    int a[2] = {m[0][0], m[0][1]};
    for (int i = 1; i < n; i++) {
        if (m[i][1] > a[1]) {
            printf("Happy Alex\n");
            break;
        }
        a[0] = m[i][0];
        a[1] = m[i][1];
    } else {
        printf("Poor Alex\n");
    }
    return 0;
}

