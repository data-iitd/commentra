

#include <stdio.h>
#include <string.h>

int main() {
    char time1[10], time2[10];
    scanf("%s %s", time1, time2);

    int h1 = (time1[0] - '0') * 10 + (time1[1] - '0');
    int m1 = (time1[3] - '0') * 10 + (time1[4] - '0');
    int h2 = (time2[0] - '0') * 10 + (time2[1] - '0');
    int m2 = (time2[3] - '0') * 10 + (time2[4] - '0');

    m1 += h1 * 60;
    m2 += h2 * 60;

    int diff = m1 - m2;
    if (diff < 0) {
        diff += 1440;
    }

    printf("%02d:%02d\n", diff / 60, diff % 60);

    return 0;
}

