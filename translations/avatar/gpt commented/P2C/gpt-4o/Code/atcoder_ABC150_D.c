#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, num;
    scanf("%d %d", &n, &num);  // Read two integers from input

    int *num_set = malloc(n * sizeof(int));  // Allocate memory for the set
    int unique_count = 0;  // To keep track of unique numbers
    int two_times_set[30] = {0};  // Array to store counts of divisions by 2

    // Read a set of integers from input
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        // Check for uniqueness
        int is_unique = 1;
        for (int j = 0; j < unique_count; j++) {
            if (num_set[j] == temp) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            num_set[unique_count++] = temp;  // Add unique number to the set
        }
    }

    // Initialize an empty set to store values related to the two times condition
    for (int i = 0; i < unique_count; i++) {
        int count = 0;
        int value = num_set[i];

        // Check how many times the number can be divided by 2
        while (value % 2 == 0) {
            value /= 2;
            count++;
        }

        if (count > 0) {
            two_times_set[count] = 1;  // Mark this count as found
        }
    }

    // If more than one unique count of divisions by 2 is found, print 0 and exit
    int found_count = 0;
    for (int i = 1; i < 30; i++) {
        if (two_times_set[i]) {
            found_count++;
        }
    }

    if (found_count != 1) {
        printf("0\n");
        free(num_set);
        return 0;
    }

    // Calculate the least common multiple (LCM)
    long long lcm = num_set[0];  // Initialize LCM with the first element of the list

    for (int i = 1; i < unique_count; i++) {
        lcm = lcm * num_set[i] / gcd(lcm, num_set[i]);  // Update LCM using the GCD
    }

    // Calculate and print the final result based on the LCM and the input number
    printf("%lld\n", (num - lcm / 2) / lcm + 1);

    free(num_set);  // Free allocated memory
    return 0;
}
