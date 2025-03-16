#include <stdio.h>

int main() {
    int h1, m1, h2, m2;

    // Read the first time input in 'hh:mm' format
    scanf("%d:%d", &h1, &m1);
    // Convert the first time into total minutes
    m1 += h1 * 60;

    // Read the second time input in 'hh:mm' format
    scanf("%d:%d", &h2, &m2);
    // Convert the second time into total minutes
    m2 += h2 * 60;

    // Calculate the difference in minutes between the first and second time
    m2 = m1 - m2;

    // Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
    m2 = (m2 + 1440) % 1440; // Adding 1440 to handle negative values

    // Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
    printf("%02d:%02d\n", m2 / 60, m2 % 60);

    return 0;
}

// <END-OF-CODE>
