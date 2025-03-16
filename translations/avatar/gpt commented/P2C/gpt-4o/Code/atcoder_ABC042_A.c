#include <stdio.h>

int main() {
    int ABC[3];
    int count5 = 0;
    int sum = 0;

    // Read a line of input and store it in the array ABC
    for (int i = 0; i < 3; i++) {
        scanf("%d", &ABC[i]);
        sum += ABC[i]; // Calculate the sum while reading
        if (ABC[i] == 5) {
            count5++; // Count occurrences of 5
        }
    }

    // Check if the number 5 appears exactly twice
    if (count5 == 2) {
        // If 5 appears twice, check if the sum equals 17
        printf("%s\n", (sum == 17) ? "YES" : "NO");
    } else {
        // If 5 does not appear exactly twice, print 'NO'
        printf("NO\n");
    }

    return 0;
}
