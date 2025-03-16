#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a work item with time and limit
typedef struct {
    int time;
    int limit;
} work;

// Define a function to sort work items based on their limits
int compare(const void *a, const void *b) {
    work *w1 = (work *)a;
    work *w2 = (work *)b;
    return w1->limit - w2->limit;
}

int main() {
    // Read the number of work items
    int n;
    scanf("%d", &n);

    // Initialize a slice to hold the work items
    work *ws = (work *)malloc(n * sizeof(work));

    // Read each work item's time and limit
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ws[i].time, &ws[i].limit);
    }

    // Sort the work items based on their limits
    qsort(ws, n, sizeof(work), compare);

    // Initialize a variable to keep track of the cumulative time
    long long sum = 0;

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

    // Free the memory allocated for the work items
    free(ws);

    return 0;
}

