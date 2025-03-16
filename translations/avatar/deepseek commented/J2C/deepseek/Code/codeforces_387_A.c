#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Step 1: Read two times from the user, split by colon and convert to LocalTime objects
    char time1[6], time2[6];
    scanf("%5s %5s", time1, time2);

    int hour1, minute1, hour2, minute2;
    sscanf(time1, "%d:%d", &hour1, &minute1);
    sscanf(time2, "%d:%d", &hour2, &minute2);

    // Step 2: Calculate the difference between the two times
    int diff_hour = hour1 - hour2;
    int diff_minute = minute1 - minute2;

    if (diff_minute < 0) {
        diff_hour -= 1;
        diff_minute += 60;
    }

    printf("%d:%02d\n", diff_hour, diff_minute);

    return 0;
}
