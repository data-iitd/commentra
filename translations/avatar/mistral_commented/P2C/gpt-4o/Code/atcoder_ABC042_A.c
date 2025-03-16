#include <stdio.h>

int main() {
    int ABC[100]; // Array to hold the integers
    int count = 0; // To count the number of elements
    int sum = 0; // To calculate the sum
    int five_count = 0; // To count occurrences of the integer 5

    // Read input until a newline is encountered
    while (1) {
        int num;
        if (scanf("%d", &num) != 1) break; // Break if input is not an integer
        ABC[count++] = num; // Store the number in the array
    }

    // Count occurrences of 5 and calculate the sum
    for (int i = 0; i < count; i++) {
        sum += ABC[i];
        if (ABC[i] == 5) {
            five_count++;
        }
    }

    // Check the conditions and print the result
    if (five_count == 2) {
        printf("%s\n", (sum == 17) ? "YES" : "NO");
    } else {
        printf("NO\n");
    }

    return 0;
}
