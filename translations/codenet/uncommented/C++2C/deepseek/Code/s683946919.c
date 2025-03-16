#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>

#define INF INT_MAX

int time2min(int month, int day, int hour, int min) {
    const int total_day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;
    for (int i = 1; i < month; i++) {
        total += total_day_of_month[i] * 24 * 60;
    }
    for (int i = 1; i < day; i++) {
        total += 24 * 60;
    }
    total += hour * 60 + min;
    return total;
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        if (N == 0) break;

        int log[1000][1000];
        memset(log, 0, sizeof(log));

        for (int i = 0; i < N; i++) {
            int month, day, hour, min, id;
            char action[2];
            scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, action, &id);

            int t = time2min(month, day, hour, min);
            log[id][0]++;
            log[id][log[id][0]] = t;
        }

        int total[1000];
        memset(total, 0, sizeof(total));

        for (int i = 1; i <= log[0][0] && i + 1 <= log[0][0]; i += 2) {
            int god_start = log[0][i];
            int god_end = log[0][i + 1];

            for (int id = 1; id < 1000; id++) {
                for (int j = 1; j <= log[id][0] && j + 1 <= log[id][0]; j += 2) {
                    int ppl_start = log[id][j];
                    int ppl_end = log[id][j + 1];
                    int start = fmax(god_start, ppl_start);
                    int end = fmin(god_end, ppl_end);
                    total[id] += fmax(0, end - start);
                }
            }
        }

        int max_v = 0;
        for (int id = 0; id < 1000; id++) {
            if (total[id] > max_v) {
                max_v = total[id];
            }
        }
        printf("%d\n", max_v);
    }
    return 0;
}
