#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Function to read integers from input
void read_input(int *n, int *m, int *lst) {
    scanf("%d %d", n, m);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &lst[i]);
    }
}

// Function to count occurrences of each integer
void count_occurrences(int *lst, int n, int *count) {
    for (int i = 0; i < n; i++) {
        count[lst[i]]++;
    }
}

int main() {
    int n, m;
    int lst[MAX_SIZE];
    int count[MAX_SIZE] = {0}; // Assuming the integers are in the range [0, MAX_SIZE-1]

    // Read the values of n and m and the list of integers
    read_input(&n, &m, lst);

    // Count the occurrences of each integer in the list
    count_occurrences(lst, n, count);

    // Initialize the result variable to store the final count
    long long res = 0;

    // Calculate the result based on the occurrences of integers
    for (int i = 0; i < n; i++) {
        if (count[lst[i]] > 1) {
            // If the current integer appears more than once
            res += n - i - count[lst[i]]; // Add the number of valid pairs
            count[lst[i]]--; // Decrease the count of this integer
        } else {
            // If the current integer appears only once
            res += n - i - 1; // Add the number of valid pairs for unique integers
        }
    }

    // Print the final result
    printf("%lld\n", res);

    return 0;
}

// <END-OF-CODE>
