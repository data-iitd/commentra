#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hour;
    int minute;
} LocalTime;

LocalTime parseTime(const char *timeStr) {
    LocalTime time;
    sscanf(timeStr, "%d:%d", &time.hour, &time.minute);
    return time;
}

LocalTime subtractTimes(LocalTime x, LocalTime y) {
    LocalTime result;
    result.hour = x.hour - y.hour;
    result.minute = x.minute - y.minute;

    // Adjust minutes and hours if necessary
    if (result.minute < 0) {
        result.minute += 60;
        result.hour--;
    }
    if (result.hour < 0) {
        result.hour += 24; // Assuming we wrap around for negative hours
    }
    return result;
}

void printTime(LocalTime time) {
    printf("%02d:%02d\n", time.hour, time.minute);
}

int main() {
    char timeStr1[6], timeStr2[6];
    
    // Step 1: Read two times from the user
    scanf("%5s %5s", timeStr1, timeStr2);
    
    LocalTime x = parseTime(timeStr1);
    LocalTime y = parseTime(timeStr2);

    // Step 2: Calculate the difference between the two times
    LocalTime result = subtractTimes(x, y);
    printTime(result);

    return 0;
}

// <END-OF-CODE>
