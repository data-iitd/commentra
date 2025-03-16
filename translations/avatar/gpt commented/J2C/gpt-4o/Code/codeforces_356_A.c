#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int answer[MAX_N];
int available[MAX_N];
int available_count = 0;

void add_available(int index) {
    available[available_count++] = index;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int ceiling(int l) {
    for (int i = 0; i < available_count; i++) {
        if (available[i] >= l) {
            return available[i];
        }
    }
    return -1; // No available position found
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Initialize the available positions
    for (int i = 0; i < n; i++) {
        add_available(i);
    }

    // Read the number of queries
    int q;
    scanf("%d", &q);

    // Process each query
    while (q-- > 0) {
        int l, r, win;
        scanf("%d %d %d", &l, &r, &win);
        l--; // Convert to 0-based index
        r--; // Convert to 0-based index

        // Update the answer array for all positions in the range [l, r]
        while (1) {
            int curr = ceiling(l);
            if (curr == -1 || curr > r) {
                break;
            }
            answer[curr] = win; // Set the answer for this position
            // Remove curr from available positions
            for (int i = 0; i < available_count; i++) {
                if (available[i] == curr) {
                    available[i] = available[--available_count]; // Remove and replace with last element
                    break;
                }
            }
        }

        // Mark the winning index as available again
        answer[win - 1] = 0;
        add_available(win - 1); // Add the winning index back to available positions
        // Sort available positions
        qsort(available, available_count, sizeof(int), compare);
    }

    // Print the final answer
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}

// <END-OF-CODE>
