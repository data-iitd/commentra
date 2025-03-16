
#include <stdio.h>
#include <string.h>

int main() {
    // Read the first time input in 'hh:mm' format and split it into hours and minutes
    char h1_str[3], m1_str[3];
    scanf("%2s:%2s", h1_str, m1_str);
    int h1 = atoi(h1_str);
    int m1 = atoi(m1_str);

    // Convert the first time into total minutes
    m1 += h1 * 60;

    // Read the second time input in 'hh:mm' format and split it into hours and minutes
    char h2_str[3], m2_str[3];
    scanf("%2s:%2s", h2_str, m2_str);
    int h2 = atoi(h2_str);
    int m2 = atoi(m2_str);

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
