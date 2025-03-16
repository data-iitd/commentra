#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[6], t[6];
    int h1, m1, h2, m2;

    scanf("%5s", s);
    scanf("%5s", t);

    h1 = (s[0] - '0') * 10 + (s[1] - '0');
    m1 = (s[3] - '0') * 10 + (s[4] - '0');
    h2 = (t[0] - '0') * 10 + (t[1] - '0');
    m2 = (t[3] - '0') * 10 + (t[4] - '0');

    int total_minutes1 = h1 * 60 + m1;
    int total_minutes2 = h2 * 60 + m2;

    int diff_minutes = total_minutes1 - total_minutes2;

    int diff_hours = diff_minutes / 60;
    int diff_minutes_final = diff_minutes % 60;

    printf("%02d:%02d\n", diff_hours, diff_minutes_final);

    return 0;
}
