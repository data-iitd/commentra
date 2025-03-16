#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000000000

// The gen function generates numbers containing only the digits 4 and 7 using recursion.
void gen(long long number, int four, int seven, int *count, long long *list) {
    // If the number exceeds the limit, return without adding it to the list.
    if (number > LIMIT) {
        return;
    }
    // If the number is positive and the count of 4's equals the count of 7's, add it to the list.
    if (number > 0 && four == seven) {
        list[*count] = number;
        (*count)++;
    }
    // Recursively generate numbers by adding 4 or 7 to the current number.
    gen(number * 10 + 4, four + 1, seven, count, list);
    gen(number * 10 + 7, four, seven + 1, count, list);
}

// The main function takes an input, finds the smallest number in the list l that is greater than or equal to n, and prints it.
int main() {
    int count = 0;
    long long *l = (long long *)malloc(1000000 * sizeof(long long)); // Allocate memory for the list
    gen(0, 0, 0, &count, l);  // Start generating numbers with 0, 0, 0 counts of 4's and 7's.

    // Sort the list l to easily find the smallest valid number.
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (l[i] > l[j]) {
                long long temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
        }
    }

    int n;
    scanf("%d", &n);  // Read the input number n.
    int ans = 0;
    // Iterate through the sorted list to find the smallest number greater than or equal to n.
    for (int i = 0; i < count; i++) {
        if (l[i] >= n) {
            ans = l[i];
            break;
        }
    }
    printf("%d\n", ans);  // Print the smallest number found.

    free(l);  // Free the allocated memory
    return 0;
}
