#include <stdio.h>
#include <stdlib.h>

// Function to read a line of input, split it into parts, and convert each part to an integer
int* read_input() {
    int* parts = (int*)malloc(2 * sizeof(int));
    scanf("%d %d", &parts[0], &parts[1]);
    return parts;
}

// Function to read a list of integers from input
int* read_list(int n) {
    int* lst = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }
    return lst;
}

// Function to count occurrences of each integer in the list
int* count_occurrences(int* lst, int n) {
    int* l = (int*)calloc(100001, sizeof(int)); // Assuming the range of integers is within 100000
    for (int i = 0; i < n; i++) {
        l[lst[i]]++;
    }
    return l;
}

int main() {
    // Read the values of n and m from input
    int* nm = read_input();
    int n = nm[0];
    int m = nm[1];

    // Read a list of integers from input
    int* lst = read_list(n);

    // Free the memory allocated for nm as it's no longer needed
    free(nm);

    // Initialize a dictionary to count occurrences of each integer in the list
    int* l = count_occurrences(lst, n);

    // Initialize the result variable to store the final count
    int res = 0;

    // Calculate the result based on the occurrences of integers
    for (int i = 0; i < n; i++) {
        if (l[lst[i]] > 1) {
            // If the current integer appears more than once
            res += n - i - l[lst[i]];  // Add the number of valid pairs
            l[lst[i]]--;  // Decrease the count of this integer
        } else {
            // If the current integer appears only once
            res += n - i - 1;  // Add the number of valid pairs for unique integers
        }
    }

    // Print the final result
    printf("%d\n", res);

    // Free the memory allocated for lst and l
    free(lst);
    free(l);

    return 0;
}
