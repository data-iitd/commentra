#include <stdio.h>
#include <stdlib.h>

int main() {
    int h1, m1, h2, m2;

    // Taking input in the format of 'HH:MM' and splitting it into hours and minutes
    scanf("%d:%d", &h1, &m1);

    // Converting hours to minutes and adding it to the minutes part
    m1 += h1 * 60;

    // Taking another input in the same format and converting it into total minutes since midnight
    scanf("%d:%d", &h2, &m2);
    m2 += h2 * 60;

    // Calculating the difference in total minutes between the two times
    m2 = m1 - m2;

    // Ensuring the result is within a 24-hour period by using modulo operation
    m2 %= 1440;

    // Printing the result in 'HH:MM' format
    printf("%02d:%02d\n", m2 / 60, m2 % 60);

    return 0;
}

