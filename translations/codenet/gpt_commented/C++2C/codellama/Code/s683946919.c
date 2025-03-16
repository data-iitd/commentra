#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define types for convenience
typedef long long ll;
typedef struct {
    int x;
    int y;
} P;
typedef struct {
    int x;
    P y;
} PP;

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
    while (~scanf("%d", &N)) {
        if (N == 0) break; // Exit if N is zero

        // Map to store the log entries for each ID
        map<int, vector<int>> log;
        for (int i = 0; i < N; i++) {
            int month, day, hour, min, id;
            char action[2];
            // Read the log entry details
            scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, action, &id);
            
            // Convert the date and time to total minutes and store in the log
            int t = time2min(month, day, hour, min);
            log[id].push_back(t);
        }

        // Array to keep track of total overlap time for each ID
        int total[1000];
        memset(total, 0, sizeof(total)); // Initialize total array to zero
        
        // Calculate overlap time for the "god" (ID 0) and other IDs
        for (int i = 0; i + 1 < log[0].size(); i += 2) {
            int god_start = log[0][i]; // Start time for god
            int god_end = log[0][i + 1]; // End time for god

            // Iterate through each log entry
            for (map<int, vector<int>>::iterator it = log.begin(); it != log.end(); it++) {
                int id = it->first; // Get the ID
                if (id == 0) continue; // Skip the god's own log

                vector<int>& schedule = it->second; // Get the schedule for the current ID
                // Calculate overlap time for each pair of start and end times
                for (int j = 0; j < schedule.size(); j += 2) {
                    int ppl_start = schedule[j]; // Start time for the person
                    int ppl_end = schedule[j + 1]; // End time for the person
                    int start = max(god_start, ppl_start); // Calculate the maximum start time
                    int end = min(god_end, ppl_end); // Calculate the minimum end time
                    total[id] += max(0, end - start); // Add the overlap time to the total
                }
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

