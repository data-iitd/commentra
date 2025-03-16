#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 1000

typedef struct {
    int id;
    int arrival;
    int departure;
} Thread;

int main() {
    int m, s, f, maxT = -1;
    scanf("%d %*s %d %d", &m, &s, &f);
    int d = (s < f) ? 1 : -1;
    int cur = s;

    Thread threads[MAX_THREADS];
    for (int i = 0; i < m; i++) {
        scanf("%d %*s %d %d", &threads[i].id, &threads[i].arrival, &threads[i].departure);
        if (threads[i].id > maxT) {
            maxT = threads[i].id;
        }
    }

    char actions[10000];
    memset(actions, 0, sizeof(actions));

    for (int t = 1; t <= maxT; t++) {
        int found = 0;
        for (int i = 0; i < m; i++) {
            if (threads[i].id == t) {
                found = 1;
                if (cur >= threads[i].arrival && cur <= threads[i].departure || cur + d >= threads[i].arrival && cur + d <= threads[i].departure) {
                    actions[strlen(actions)] = 'X';
                } else {
                    actions[strlen(actions)] = (s < f) ? 'R' : 'L';
                    cur += d;
                }
                if (cur == f) {
                    break;
                }
            }
        }
        if (!found) {
            actions[strlen(actions)] = (s < f) ? 'R' : 'L';
            cur += d;
        }
        if (cur == f) {
            break;
        }
    }

    printf("%s\n", actions);
    return 0;
}
