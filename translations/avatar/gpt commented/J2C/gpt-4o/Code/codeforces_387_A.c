#include <stdio.h> // Including standard input/output library
#include <stdlib.h> // Including standard library for atoi function
#include <time.h> // Including time library for struct tm

int main() {
    // Variables to hold hours and minutes
    int h1, m1, h2, m2;
    
    // Reading two time inputs in "HH:MM" format
    char time1[6], time2[6];
    scanf("%5s %5s", time1, time2);
    
    // Splitting the first time input into hours and minutes
    sscanf(time1, "%d:%d", &h1, &m1);
    
    // Splitting the second time input into hours and minutes
    sscanf(time2, "%d:%d", &h2, &m2);
    
    // Creating struct tm to represent the first and second time
    struct tm time1_tm = {0};
    struct tm time2_tm = {0};
    
    time1_tm.tm_hour = h1;
    time1_tm.tm_min = m1;
    time1_tm.tm_sec = 0;
    
    time2_tm.tm_hour = h2;
    time2_tm.tm_min = m2;
    time2_tm.tm_sec = 0;
    
    // Converting struct tm to time_t for difference calculation
    time_t t1 = mktime(&time1_tm);
    time_t t2 = mktime(&time2_tm);
    
    // Calculating the difference in seconds
    double difference = difftime(t1, t2);
    
    // Converting the difference back to hours and minutes
    int diff_hours = (int)(difference / 3600);
    int diff_minutes = (int)((difference - (diff_hours * 3600)) / 60);
    
    // Printing the result
    printf("%02d:%02d\n", diff_hours, diff_minutes);
    
    return 0;
}

// <END-OF-CODE>
