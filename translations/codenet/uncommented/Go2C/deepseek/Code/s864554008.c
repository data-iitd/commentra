#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n, m;
    char **nImg, **mImg;
} data;

data* newData() {
    data *d = (data*)malloc(sizeof(data));
    scanf("%d %d", &d->n, &d->m);
    d->nImg = load(d->n);
    d->mImg = load(d->m);
    return d;
}

char** load(int cnt) {
    char **ret = (char**)malloc(cnt * sizeof(char*));
    for (int i = 0; i < cnt; i++) {
        ret[i] = (char*)malloc(100 * sizeof(char)); // Assuming max length of each string is 100
        scanf("%s", ret[i]);
    }
    return ret;
}

int exist(data *d) {
    for (int i = 0; i <= d->n - d->m; i++) {
        for (int j = 0; j <= d->n - d->m; j++) {
            if (match(d, i, j)) {
                return 1;
            }
        }
    }
    return 0;
}

int match(data *d, int x, int y) {
    for (int i = 0; i < d->m; i++) {
        for (int j = 0; j < d->m; j++) {
            if (d->nImg[x + i][y + j] != d->mImg[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    data *d = newData();
    if (exist(d)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    // Free allocated memory
    for (int i = 0; i < d->n; i++) {
        free(d->nImg[i]);
    }
    free(d->nImg);
    for (int i = 0; i < d->m; i++) {
        free(d->mImg[i]);
    }
    free(d->mImg);
    free(d);
    return 0;
}
