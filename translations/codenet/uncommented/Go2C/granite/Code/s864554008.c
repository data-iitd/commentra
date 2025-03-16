
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n, m;
    char **nImg, **mImg;
} data;

data newData();
char **load(int);
int exist(data);
int match(data, int, int);

int main() {
    data d = newData();
    if (exist(d)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

data newData() {
    int n, m;
    scanf("%d %d", &n, &m);
    char **nImg = load(n);
    char **mImg = load(m);
    return (data){n, m, nImg, mImg};
}

char **load(int cnt) {
    char **ret = (char **)malloc(cnt * sizeof(char *));
    for (int i = 0; i < cnt; i++) {
        ret[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", ret[i]);
    }
    return ret;
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
            if (d.nImg[x + i][y + j]!= d.mImg[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}
