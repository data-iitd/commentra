#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int values[2];
} Interval;

int main() {
    int m, s, f;
    scanf("%d %d %d", &m, &s, &f);

    Interval intervals[m];
    int maxT = -1;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &intervals[i].key, &intervals[i].values[0], &intervals[i].values[1]);
        if (intervals[i].key > maxT) {
            maxT = intervals[i].key;
        }
    }

    char actions[maxT + abs(s - f) + 1];
    int cur = s;
    int d = (s < f) ? 1 : -1;
    int actionIndex = 0;

    for (int t = 1; t <= maxT; t++) {
        int intervalFound = -1;
        for (int i = 0; i < m; i++) {
            if (intervals[i].key == t) {
                intervalFound = i;
                break;
            }
        }

        if (intervalFound != -1) {
            int a = intervals[intervalFound].values[0];
            int b = intervals[intervalFound].values[1];

            if ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b)) {
                actions[actionIndex++] = 'X';
            } else {
                actions[actionIndex++] = (s < f) ? 'R' : 'L';
                cur += d;
            }
        } else {
            actions[actionIndex++] = (s < f) ? 'R' : 'L';
            cur += d;
        }

        if (cur == f) {
            break;
        }
    }

    while (cur != f) {
        actions[actionIndex++] = (s < f) ? 'R' : 'L';
        cur += d;
    }

    actions[actionIndex] = '\0';
    printf("%s\n", actions);

    return 0;
}
