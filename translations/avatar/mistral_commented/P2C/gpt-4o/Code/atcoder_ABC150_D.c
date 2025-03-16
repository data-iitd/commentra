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
    // Taking input of n and number of distinct numbers
    int n, num;
    scanf("%d %d", &n, &num);

    // Creating a set of distinct numbers
    int *num_set = (int *)malloc(num * sizeof(int));
    int *distinct = (int *)malloc(num * sizeof(int));
    int distinct_count = 0;

    for (int i = 0; i < num; i++) {
        int x;
        scanf("%d", &x);
        // Check for distinctness
        int is_distinct = 1;
        for (int j = 0; j < distinct_count; j++) {
            if (distinct[j] == x) {
                is_distinct = 0;
                break;
            }
        }
        if (is_distinct) {
            distinct[distinct_count++] = x;
        }
    }

    // Finding the powers of 2 that appear exactly twice in the binary representation of each number in distinct
    int two_times_set[2] = {0}; // Only need to track 0 and 1
    int two_times_count = 0;

    for (int i = 0; i < distinct_count; i++) {
        int power_of_two = 0;
        int value = distinct[i];

        // Dividing value by 2 repeatedly until it is no longer even
        while (value % 2 == 0) {
            power_of_two++;
            value /= 2;
        }

        // If the number of times 2 is divided is not exactly 1, then the answer is 0
        if (power_of_two > 1) {
            printf("0\n");
            free(num_set);
            free(distinct);
            return 0;
        }

        // Add the power of 2 to two_times_set
        if (power_of_two < 2) {
            two_times_set[power_of_two] = 1;
        }
    }

    // If the size of two_times_set is not exactly 1, then the answer is 0
    if (two_times_set[0] + two_times_set[1] != 1) {
        printf("0\n");
        free(num_set);
        free(distinct);
        return 0;
    }

    // Finding the least common multiple of all numbers in distinct
    int lcm = distinct[0];

    // Finding the least common multiple of the first number and the next number
    for (int i = 1; i < distinct_count; i++) {
        lcm = lcm * distinct[i] / gcd(lcm, distinct[i]);
    }

    // Printing the answer
    printf("%d\n", (num - lcm / 2) / lcm + 1);

    free(num_set);
    free(distinct);
    return 0;
}
