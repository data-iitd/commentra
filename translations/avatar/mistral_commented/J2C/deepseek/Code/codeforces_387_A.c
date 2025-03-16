#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables to store the time strings
    char time1[6], time2[6];
    // Declare variables to store the hour and minute parts
    int hour1, minute1, hour2, minute2;

    // Read the first time string from the console
    scanf("%5s", time1);
    // Read the second time string from the console
    scanf("%5s", time2);

    // Extract the hour and minute parts from the first time string
    sscanf(time1, "%d:%d", &hour1, &minute1);
    // Extract the hour and minute parts from the second time string
    sscanf(time2, "%d:%d", &hour2, &minute2);

    // Calculate the difference between the two times in minutes
    int total_minutes1 = hour1 * 60 + minute1;
    int total_minutes2 = hour2 * 60 + minute2;
    int difference_minutes = total_minutes1 - total_minutes2;

    // Calculate the difference in hours and minutes
    int difference_hours = difference_minutes / 60;
    int difference_minutes_final = difference_minutes % 60;

    // Print the result
    printf("%d:%02d\n", difference_hours, difference_minutes_final);

    return 0;
}
