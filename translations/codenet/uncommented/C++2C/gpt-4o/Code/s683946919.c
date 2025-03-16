#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF 0x3f3f3f3f
<<<<<<< HEAD
#define MAX_ID 1000
=======
>>>>>>> 98c87cb78a (data updated)

int time2min(int month, int day, int hour, int min) {
    const int total_day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;
    for (int i = 1; i < month; i++) {
        total += total_day_of_month[i - 1] * 24 * 60;
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

<<<<<<< HEAD
        int log[MAX_ID][100]; // Assuming a maximum of 100 entries per ID
        int log_size[MAX_ID] = {0}; // To keep track of the number of entries for each ID

=======
        int log[1000][100]; // Assuming a maximum of 100 logs per ID
        int log_count[1000] = {0}; // To keep track of the number of logs for each ID
>>>>>>> 98c87cb78a (data updated)
        for (int i = 0; i < N; i++) {
            int month, day, hour, min, id;
            char action[2];
            scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, action, &id);

            int t = time2min(month, day, hour, min);
<<<<<<< HEAD
            log[id][log_size[id]++] = t;
        }

        int total[MAX_ID] = {0};
=======
            log[id][log_count[id]++] = t;
        }

        int total[1000] = {0};
>>>>>>> 98c87cb78a (data updated)

        for (int i = 0; i + 1 < log[0][0]; i += 2) {
            int god_start = log[0][i];
            int god_end = log[0][i + 1];

<<<<<<< HEAD
            for (int id = 1; id < MAX_ID; id++) {
                if (log_size[id] == 0) continue; // Skip if no entries for this ID
                for (int j = 0; j + 1 < log_size[id]; j += 2) {
=======
            for (int id = 1; id < 1000; id++) {
                if (log_count[id] == 0) continue; // Skip if no logs for this ID
                for (int j = 0; j < log_count[id]; j += 2) {
>>>>>>> 98c87cb78a (data updated)
                    int ppl_start = log[id][j];
                    int ppl_end = log[id][j + 1];
                    int start = (god_start > ppl_start) ? god_start : ppl_start;
                    int end = (god_end < ppl_end) ? god_end : ppl_end;
                    total[id] += (end > start) ? (end - start) : 0;
                }
            }
        }

        int max_v = 0;
<<<<<<< HEAD
        for (int id = 0; id < MAX_ID; id++) {
=======
        for (int id = 0; id < 1000; id++) {
>>>>>>> 98c87cb78a (data updated)
            if (total[id] > max_v) {
                max_v = total[id];
            }
        }
        printf("%d\n", max_v);
    }
    return 0;
}

// <END-OF-CODE>
