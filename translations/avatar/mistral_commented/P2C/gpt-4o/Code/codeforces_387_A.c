#include <stdio.h>

int main() {
    int h1, m1, h2, m2;

    // Define the first hour and minute variables from user input
    scanf("%d:%d", &h1, &m1);

    // Add the hour to the minute value
    m1 += h1 * 60;

    // Define the second hour and minute variables from user input
    scanf("%d:%d", &h2, &m2);

    // Add the hour to the minute value for the second set of variables
    m2 += h2 * 60;

    // Calculate the difference between the total minutes of the first and second sets of variables
    m2 = m1 - m2;

    // Calculate the remainder of the difference when divided by 1440 (24 hours * 60 minutes)
    m2 %= 1440;

    // Print the result in the format of hours and minutes
    printf("%02d:%02d\n", m2 / 60, m2 % 60);

    return 0;
}

// <END-OF-CODE>
