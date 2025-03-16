#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF 0x3f3f3f3f
#define MAX_ID 1000

// Function to convert date, hour and minute to total minutes
int time2min(int month, int day, int hour, int min) {
    const int total_day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Total days in each month
    int total = 0;
    for (int i = 1; i < month; i++) { // Calculate total minutes for each month before the current one
        total += total_day_of_month[i] * 24 * 60;
    }
    for (int i = 1; i < day; i++) { // Calculate total minutes for each day before the current one
        total += 24 * 60;
    }
    total += hour * 60 + min; // Calculate total minutes for the current hour and minute

    return total;
}

int main() {
    int N; // Number of logs
    while (scanf("%d", &N) != EOF) { // Read the number of logs from the standard input
        if (N == 0) break; // If the number of logs is zero, break the loop

        int log[MAX_ID][100]; // Create a 2D array to store logs for each id
        int log_count[MAX_ID] = {0}; // Array to keep track of the number of logs for each id

        for (int i = 0; i < N; i++) { // Iterate through each log
            int month, day, hour, min, id; // Read the month, day, hour, minute and id from the standard input
            char action[2]; // Read the action (add or remove) from the standard input

            scanf("%d/%d %d:%d %s %d", // Read the month, day, hour, minute, action and id from the standard input
                  &month, &day, &hour, &min, action, &id);

            int t = time2min(month, day, hour, min); // Calculate the total minutes for the log
            log[id][log_count[id]++] = t; // Add the total minutes to the array of logs for the id
        }

        int total[MAX_ID] = {0}; // Create an array to store the total time spent for each id

        for (int i = 0; i + 1 < log_count[0]; i += 2) { // Iterate through each pair of logs for the id 0
            int god_start = log[0][i]; // Get the start time of the first log
            int god_end = log[0][i + 1]; // Get the end time of the first log

            for (int id = 1; id < MAX_ID; id++) { // Iterate through each id and its logs
                if (log_count[id] == 0) continue; // If there are no logs for this id, skip

                for (int j = 0; j + 1 < log_count[id]; j += 2) { // Iterate through each pair of logs for the current id
                    int ppl_start = log[id][j]; // Get the start time of the first log
                    int ppl_end = log[id][j + 1]; // Get the end time of the first log
                    int start = (god_start > ppl_start) ? god_start : ppl_start; // Get the maximum start time
                    int end = (god_end < ppl_end) ? god_end : ppl_end; // Get the minimum end time
                    total[id] += (end > start) ? (end - start) : 0; // Calculate and add the total time spent for the current id
                }
            }
        }

        int max_v = 0; // Initialize the maximum total time spent to zero
        for (int id = 0; id < MAX_ID; id++) { // Iterate through each id and find the maximum total time spent
            if (total[id] > max_v) {
                max_v = total[id];
            }
        }
        printf("%d\n", max_v); // Print the maximum total time spent
    }
    return 0;
}
