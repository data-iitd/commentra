
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a work item with time and limit
typedef struct {
    int time, limit;
} work;

// Define a function to compare two work items based on their limits
int compare_works(const void *a, const void *b) {
    work *wa = (work *)a;
    work *wb = (work *)b;
    return wa->limit - wb->limit;
}

// Define a function to read the number of work items and their time and limit
void read_works(int n, work *ws) {
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ws[i].time, &ws[i].limit);
    }
}

// Define a function to check if the cumulative time exceeds the limit for any work item
int check_works(int n, work *ws) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ws[i].time;
        if (sum > ws[i].limit) {
            return 0; // Return 0 if the sum exceeds the limit
        }
    }
    return 1; // Return 1 if all work items are within their limits
}

// Define the main function
int main() {
    int n;
    scanf("%d", &n);
    work *ws = (work *)malloc(n * sizeof(work));
    read_works(n, ws);
    qsort(ws, n, sizeof(work), compare_works);
    int result = check_works(n, ws);
    if (result == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    free(ws);
    return 0;
}

// End of code
