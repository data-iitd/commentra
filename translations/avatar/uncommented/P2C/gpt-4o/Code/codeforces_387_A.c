#include <stdio.h>

int main() {
    int h1, m1, h2, m2;
    
    // Read first time input
    scanf("%d:%d", &h1, &m1);
    m1 += h1 * 60; // Convert to minutes

    // Read second time input
    scanf("%d:%d", &h2, &m2);
    m2 += h2 * 60; // Convert to minutes

    // Calculate the difference in minutes
    m2 = m1 - m2;
    m2 %= 1440; // Ensure it's within a day

    // Print the result in HH:MM format
    printf("%02d:%02d\n", m2 / 60, m2 % 60);

    return 0;
}

// <END-OF-CODE>
