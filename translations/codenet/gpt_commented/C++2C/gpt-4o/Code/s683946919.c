#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF 0x3f3f3f3f
<<<<<<< HEAD
#define MAX_IDS 1000
=======
>>>>>>> 98c87cb78a (data updated)

// Function to convert date and time into total minutes from the start of the year
int time2min(int month, int day, int hour, int min) {
    // Array containing the total days in each month
    const int total_day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;

    // Calculate total minutes for the months before the given month
    for (int i = 1; i < month; i++) {
        total += total_day_of_month[i] * 24 * 60;
    }
    
    // Add total minutes for the days before the given day
    for (int i = 1; i < day; i++) {
        total += 24 * 60;
    }
    
    // Add minutes for the given hour and minute
    total += hour * 60 + min;

    return total; // Return total minutes
}

int main() {
    int N;
    // Read the number of logs until a zero is encountered
    while (scanf("%d", &N) != EOF) {
        if (N == 0) break; // Exit if N is zero

        // Array to store the log entries for each ID
<<<<<<< HEAD
        int log[MAX_IDS][100]; // Assuming a maximum of 100 logs per ID
        int log_count[MAX_IDS] = {0}; // To keep track of the number of logs for each ID
=======
        int log[1000][100]; // Assuming a maximum of 100 logs per ID
        int log_count[1000] = {0}; // To keep track of the number of logs for each ID
>>>>>>> 98c87cb78a (data updated)

        for (int i = 0; i < N; i++) {
            int month, day, hour, min, id;
            char action[2];
            // Read the log entry details
            scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, action, &id);
            
            // Convert the date and time to total minutes and store in the log
            int t = time2min(month, day, hour, min);
<<<<<<< HEAD
            log[id][log_count[id]++] = t; // Store the time in the log for the given ID
        }

        // Array to keep track of total overlap time for each ID
        int total[MAX_IDS] = {0}; // Initialize total array to zero
=======
            log[id][log_count[id]++] = t; // Store the time in the log for the corresponding ID
        }

        // Array to keep track of total overlap time for each ID
        int total[1000] = {0}; // Initialize total array to zero
>>>>>>> 98c87cb78a (data updated)
        
        // Calculate overlap time for the "god" (ID 0) and other IDs
        for (int i = 0; i + 1 < log_count[0]; i += 2) {
            int god_start = log[0][i]; // Start time for god
            int god_end = log[0][i + 1]; // End time for god

            // Iterate through each log entry
<<<<<<< HEAD
            for (int id = 1; id < MAX_IDS; id++) {
=======
            for (int id = 1; id < 1000; id++) {
>>>>>>> 98c87cb78a (data updated)
                if (log_count[id] == 0) continue; // Skip if there are no logs for this ID

                // Calculate overlap time for each pair of start and end times
                for (int j = 0; j + 1 < log_count[id]; j += 2) {
                    int ppl_start = log[id][j]; // Start time for the person
                    int ppl_end = log[id][j + 1]; // End time for the person
                    int start = (god_start > ppl_start) ? god_start : ppl_start; // Calculate the maximum start time
                    int end = (god_end < ppl_end) ? god_end : ppl_end; // Calculate the minimum end time
                    total[id] += (end > start) ? (end - start) : 0; // Add the overlap time to the total
                }
            }
        }

        // Find the maximum overlap time among all IDs
        int max_v = 0;
<<<<<<< HEAD
        for (int id = 0; id < MAX_IDS; id++) {
=======
        for (int id = 0; id < 1000; id++) {
>>>>>>> 98c87cb78a (data updated)
            if (total[id] > max_v) {
                max_v = total[id]; // Update max_v if current total is greater
            }
        }
        
        // Output the maximum overlap time
        printf("%d\n", max_v);
    }
    return 0;
}

// <END-OF-CODE>
