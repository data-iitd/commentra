
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int x[n], y[m];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // Process the jobs in the heap until it's empty
    for (int i = 0; i < n; i++) {
        int max_index = 0;
        for (int j = 1; j < n; j++) {
            if (x[j] > x[max_index]) {
                max_index = j;
            }
        }

        // Calculate the remaining capacity for jobs
        int remaining_capacity = m - i;

        // If there is enough capacity to take the job
        if (remaining_capacity >= x[max_index]) {
            // Add the salary to the selected salaries heap
            y[i] = y[max_index];
            x[max_index] = -1;  // Mark the job as processed
        } else {
            // If capacity is full, replace the lowest salary if the new salary is higher
            int min_index = 0;
            for (int j = 1; j < m; j++) {
                if (y[j] < y[min_index]) {
                    min_index = j;
                }
            }
            y[min_index] = y[max_index];
            x[max_index] = -1;  // Mark the job as processed
        }
    }

    // Output the total sum of selected salaries
    int total_sum = 0;
    for (int i = 0; i < m; i++) {
        total_sum += y[i];
    }
    printf("%d\n", total_sum);

    return 0;
}
