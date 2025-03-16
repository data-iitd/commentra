#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int m, s, f;
    scanf("%d %d %d", &m, &s, &f);
    int maxT = -1;
    int** map = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        map[i] = (int*)malloc(3 * sizeof(int));
    }
    char actions[100000];
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;
    int a = -1, b = -1;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
        if (map[i][0] > maxT) {
            maxT = map[i][0];
        }
    }

    for (int t = 1; t <= maxT; t++) {
        int found = 0;
        for (int i = 0; i < m; i++) {
            if (map[i][0] == t) {
                a = map[i][1];
                b = map[i][2];
                found = 1;
                break;
            }
        }
        if (found && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            strcat(actions, "X");
        } else {
            char temp[2] = {M, '\0'};
            strcat(actions, temp);
            cur += d;
        }
        if (cur == f) break;
    }

    while (cur != f) {
        char temp[2] = {M, '\0'};
        strcat(actions, temp);
        cur += d;
    }

    printf("%s\n", actions);

    for (int i = 0; i < m; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}
