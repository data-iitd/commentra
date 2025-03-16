#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[6], t[6];
    int sh, sm, th, tm;
    
    // Reading two time inputs in "HH:MM" format
    scanf("%5s %5s", s, t);
    
    // Extracting hours and minutes from the input strings
    sh = (s[0] - '0') * 10 + (s[1] - '0');
    sm = (s[3] - '0') * 10 + (s[4] - '0');
    th = (t[0] - '0') * 10 + (t[1] - '0');
    tm = (t[3] - '0') * 10 + (t[4] - '0');
    
    // Calculating the difference between the two times
    int diff_hours = sh - th;
    int diff_minutes = sm - tm;
    
    // Adjusting for negative minutes
    if (diff_minutes < 0) {
        diff_minutes += 60;
        diff_hours -= 1;
    }
    
    // Adjusting for negative hours
    if (diff_hours < 0) {
        diff_hours += 24;
    }
    
    // Printing the result
    printf("%02d:%02d\n", diff_hours, diff_minutes);
    
    return 0;
}
