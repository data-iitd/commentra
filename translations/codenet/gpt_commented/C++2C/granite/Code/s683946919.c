
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define types for convenience
typedef long long ll;
typedef struct {
    int month, day, hour, min;
} DateTime;

// Function to convert date and time into total minutes from the start of the year
int time2min(DateTime dt) {
    // Array containing the total days in each month
    const int total_day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;

    // Calculate total minutes for the months before the given month
    for (int i = 1; i < dt.month; i++) {
        total += total_day_of_month[i] * 24 * 60;
    }
    
    // Add total minutes for the days before the given day
    for (int i = 1; i < dt.day; i++) {
        total += 24 * 60;
    }
    
    // Add minutes for the given hour and minute
    total += dt.hour * 60 + dt.min;

    return total; // Return total minutes
}

int main() {
    int N;
    // Read the number of logs until a zero is encountered
    while (~scanf("%d", &N)) {
        if (N == 0) break; // Exit if N is zero

        // Map to store the log entries for each ID
        typedef struct {
            int id;
            DateTime dt[2];
        } Log;
        Log logs[N];
        for (int i = 0; i < N; i++) {
            int month, day, hour, min;
            char action[2];
            // Read the log entry details
            scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, action, &logs[i].id);
            logs[i].dt[0].month = month;
            logs[i].dt[0].day = day;
            logs[i].dt[0].hour = hour;
            logs[i].dt[0].min = min;
            logs[i].dt[1].month = month;
            logs[i].dt[1].day = day;
            logs[i].dt[1].hour = hour;
            logs[i].dt[1].min = min;
        }

        // Array to keep track of total overlap time for each ID
        int total[1000];
        memset(total, 0, sizeof(total)); // Initialize total array to zero
        
        // Calculate overlap time for the "god" (ID 0) and other IDs
        for (int i = 0; i + 1 < logs[0].dt[0].month; i += 2) {
            DateTime god_dt[2];
            god_dt[0] = logs[0].dt[i]; // Start time for god
            god_dt[1] = logs[0].dt[i + 1]; // End time for god

            // Iterate through each log entry
            for (int j = 0; j < N; j++) {
                if (logs[j].id == 0) continue; // Skip the god's own log

                DateTime ppl_dt[2];
                ppl_dt[0] = logs[j].dt[0]; // Start time for the person
                ppl_dt[1] = logs[j].dt[1]; // End time for the person
                int start = max(god_dt[0].month, ppl_dt[0].month); // Calculate the maximum start time
                int end = min(god_dt[1].month, ppl_dt[1].month); // Calculate the minimum end time
                total[logs[j].id] += max(0, end - start); // Add the overlap time to the total
            }
        }

        // Find the maximum overlap time among all IDs
        int max_v = 0;
        for (int id = 0; id < 1000; id++) {
            max_v = max(total[id], max_v); // Update max_v if current total is greater
        }
        
        // Output the maximum overlap time
        printf("%d\n", max_v);
    }
}


Translate the above C code to C++ and end with comment "