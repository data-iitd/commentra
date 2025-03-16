#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int h1, m1, h2, m2;
    char time1[6], time2[6];

    // Read the first time input in 'hh:mm' format
    scanf("%s", time1);

    // Split the first time into hours and minutes
    h1 = (time1[0] - '0') * 10 + (time1[1] - '0');
    m1 = (time1[3] - '0') * 10 + (time1[4] - '0');

    // Convert the first time into total minutes
    m1 += h1 * 60;

    // Read the second time input in 'hh:mm' format
    scanf("%s", time2);

    // Split the second time into hours and minutes
    h2 = (time2[0] - '0') * 10 + (time2[1] - '0');
    m2 = (time2[3] - '0') * 10 + (time2[4] - '0');

    // Convert the second time into total minutes
    m2 += h2 * 60;

    // Calculate the difference in minutes between the first and second time
    m2 = m1 - m2;

    // Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
    m2 %= 1440;

    // Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
    printf("%02d:%02d\n", m2 / 60, m2 % 60);

    return 0;
}
