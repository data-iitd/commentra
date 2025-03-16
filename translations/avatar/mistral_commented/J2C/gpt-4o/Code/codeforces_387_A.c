#include <stdio.h>  // Include standard input/output library
#include <stdlib.h> // Include standard library for atoi
#include <time.h>   // Include time library for struct tm

int main() {
    // Declare variables for hours and minutes
    int hour1, minute1, hour2, minute2;
    
    // Read the first time string from the console
    char time1[6]; // Format HH:MM
    scanf("%5s", time1);
    
    // Read the second time string from the console
    char time2[6]; // Format HH:MM
    scanf("%5s", time2);
    
    // Parse the first time string
    sscanf(time1, "%d:%d", &hour1, &minute1);
    
    // Parse the second time string
    sscanf(time2, "%d:%d", &hour2, &minute2);
    
    // Calculate the total minutes for both times
    int totalMinutes1 = hour1 * 60 + minute1;
    int totalMinutes2 = hour2 * 60 + minute2;
    
    // Calculate the difference in minutes
    int difference = totalMinutes1 - totalMinutes2;
    
    // Convert the difference back to hours and minutes
    int diffHours = difference / 60;
    int diffMinutes = difference % 60;
    
    // Print the result
    printf("%02d:%02d\n", diffHours, diffMinutes);
    
    return 0;
}
