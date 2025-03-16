


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Entry point of the program
int main(int argc, char *argv[]) {
    // Read the number of work items
    int n;
    scanf("%d", &n);

    // Initialize a slice to hold the work items
    work *ws = (work *) malloc(n * sizeof(work));

    // Read each work item's time and limit
    for (int i = 0; i < n; i++) {
        int a, n;
        scanf("%d %d", &a, &n);
        ws[i] = (work) {a, n}; // Store the work item in the slice
    }

    // Sort the work items based on their limits
    qsort(ws, n, sizeof(work), (int (*)(const void *, const void *)) work_compare);

    // Initialize a variable to keep track of the cumulative time
    int64_t sum = 0;

    // Check if the cumulative time exceeds the limit for any work item
    for (int i = 0; i < n; i++) {
        sum += ws[i].time; // Add the current work item's time to the sum
        if (sum > ws[i].limit) {
            printf("No\n"); // If the sum exceeds the limit, print "No"
            return 0;
        }
    }

    // If all work items are within their limits, print "Yes"
    printf("Yes\n");

    return 0;
}

// Define a struct to represent a work item with time and limit
typedef struct {
    int time;
    int limit;
} work;

// Compare two work items based on their limits
int work_compare(const void *a, const void *b) {
    work *wa = (work *) a;
    work *wb = (work *) b;
    return wa->limit - wb->limit;
}

