#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int n, m;
    char nImg[MAX_SIZE][MAX_SIZE];
    char mImg[MAX_SIZE][MAX_SIZE];
} data;

data newData() {
    data d;
    scanf("%d %d", &d.n, &d.m);
    for (int i = 0; i < d.n; i++) {
        scanf("%s", d.nImg[i]);
    }
    for (int i = 0; i < d.m; i++) {
        scanf("%s", d.mImg[i]);
    }

    return d;
}

int exist(data d) {
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            if (match(d, i, j)) {
                return 1;
            }
        }
    }

    return 0;
}

int match(data d, int x, int y) {
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            if (d.nImg[x+i][y+j] != d.mImg[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    data d = newData();
    if (exist(d)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

