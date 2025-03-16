#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[6], t[6];
    int sh, sm, th, tm;

    // Read input times in HH:MM format
    scanf("%s %s", s, t);

    // Parse the first time
    sh = atoi(strtok(s, ":"));
    sm = atoi(strtok(NULL, ":"));

    // Parse the second time
    th = atoi(strtok(t, ":"));
    tm = atoi(strtok(NULL, ":"));

    // Calculate the difference in minutes
    int totalMinutesX = sh * 60 + sm;
    int totalMinutesY = th * 60 + tm;
    int difference = totalMinutesX - totalMinutesY;

    // Convert the difference back to hours and minutes
    int hours = difference / 60;
    int minutes = difference % 60;

    // Print the result
    printf("%d:%02d\n", hours, minutes);

    return 0;
}

// <END-OF-CODE>
