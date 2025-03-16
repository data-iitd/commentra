#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n, m;
    char **nImg, **mImg;
} Data;

Data newData();
char **load(int cnt);
int exist(Data d);
int match(Data d, int x, int y);

int main() {
    Data d = newData();
    if (exist(d)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Free allocated memory
    for (int i = 0; i < d.n; i++) {
        free(d.nImg[i]);
    }
    free(d.nImg);
    
    for (int i = 0; i < d.m; i++) {
        free(d.mImg[i]);
    }
    free(d.mImg);

    return 0;
}

Data newData() {
    Data d;
    scanf("%d %d", &d.n, &d.m);
    d.nImg = load(d.n);
    d.mImg = load(d.m);
    return d;
}

char **load(int cnt) {
    char **ret = malloc(cnt * sizeof(char *));
    for (int i = 0; i < cnt; i++) {
        ret[i] = malloc(100 * sizeof(char)); // Assuming max length of each string is 99
        scanf("%s", ret[i]);
    }
    return ret;
}

int exist(Data d) {
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            if (match(d, i, j)) {
                return 1; // true
            }
        }
    }
    return 0; // false
}

int match(Data d, int x, int y) {
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            if (d.nImg[x + i][y + j] != d.mImg[i][j]) {
                return 0; // false
            }
        }
    }
    return 1; // true
}

// <END-OF-CODE>
