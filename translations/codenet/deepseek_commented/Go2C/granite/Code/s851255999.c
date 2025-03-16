

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int limit;
} work;

typedef struct {
    work *works;
    int length;
} works;

int compare_works(const void *a, const void *b) {
    work *wa = (work *)a;
    work *wb = (work *)b;
    return wa->limit - wb->limit;
}

int main() {
    // Read the number of works
    int n;
    scanf("%d", &n);

    // Create a slice of work structs with a length of n
    work *ws = (work *)malloc(sizeof(work) * n);

    // Read the time and limit for each work and store them in the slice
    for (int i = 0; i < n; i++) {
        int a, n;
        scanf("%d %d", &a, &n);
        ws[i] = (work){a, n};
    }

    // Sort the slice of works based on the limit field
    qsort(ws, n, sizeof(work), compare_works);

    // Initialize a sum variable to keep track of the cumulative time
    long long sum = 0;

    // Iterate over the sorted slice of works, adding the time of each work to the sum
    for (int i = 0; i < n; i++) {
        sum += ws[i].time;

        // Check if the cumulative time exceeds the limit of the current work
        if (sum > ws[i].limit) {
            printf("No\n");
            return 0;
        }
    }

    // If the loop completes without the sum exceeding any limit, print "Yes"
    printf("Yes\n");

    // Free the memory allocated for the work slice
    free(ws);

    return 0;
}

