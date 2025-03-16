#include <stdio.h>

int main() {
    int t, count = 0;
    scanf("%d", &t); // Step 4: Read the number of test cases

    // Step 7: Use a for loop to iterate through each test case
    for (int i = 0; i < t; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c); // Step 8: Read the values of a, b, and c for each test case

        // Step 9: Check if any of the values are 1 or if all three values are 1
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
            count++; // Step 10: Increment the counter if the condition is met
        }
    }

    // Step 11: Print the counter value after the loop
    printf("%d\n", count);

