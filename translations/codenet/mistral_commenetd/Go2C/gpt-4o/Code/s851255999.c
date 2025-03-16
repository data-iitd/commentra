#include <stdio.h>
#include <stdlib.h>

// Define a structure named "work" with two fields: "time" and "limit"
typedef struct {
    int time;
    int limit;
} work;

// Comparison function for qsort to sort works by limit
int compare(const void *a, const void *b) {
    work *workA = (work *)a;
    work *workB = (work *)b;
    return workA->limit - workB->limit;
}

int main() {
    // Declare variables and initialize them
    int n;
    scanf("%d", &n);

    // Create an array of work structures with length "n"
    work *ws = (work *)malloc(n * sizeof(work));

    // Read input data for each work structure and store it in the corresponding index of the "ws" array
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ws[i].time, &ws[i].limit);
    }

    // Sort the "ws" array based on the "limit" field of each work structure
    qsort(ws, n, sizeof(work), compare);

    // Initialize a variable named "sum" of type long long and set its value to 0
    long long sum = 0;

    // Iterate through the sorted "ws" array and check if the total time spent on all works exceeds any work's limit
    for (int i = 0; i < n; i++) {
        // Add the time of the current work structure to the "sum" variable
        sum += ws[i].time;

        // Check if the sum is greater than the limit of the current work structure
        if (sum > ws[i].limit) {
            // If it is, print "No" and return from the function
            printf("No\n");
            free(ws);
            return 0;
        }
    }

    // If the loop completes without finding a work structure whose time exceeds its limit, print "Yes"
    printf("Yes\n");

    // Free the allocated memory
    free(ws);
    return 0;
}

// <END-OF-CODE>
