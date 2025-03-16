#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int salary;
} Job;

int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    if (jobA->day == jobB->day) {
        return jobB->salary - jobA->salary; // Max-heap based on salary
    }
    return jobB->day - jobA->day; // Max-heap based on day
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Job *jobs = (Job *)malloc(n * sizeof(Job));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jobs[i].day, &jobs[i].salary);
    }

    // Sort jobs to simulate a max-heap
    qsort(jobs, n, sizeof(Job), compare);

    int *y = (int *)malloc(m * sizeof(int));
    int y_count = 0;
    int total_salary = 0;

    for (int i = 0; i < n; i++) {
        int d = jobs[i].day;
        int s = jobs[i].salary;

        int r = m - y_count;
        if (r >= d) {
            y[y_count++] = s; // Add salary to y
            total_salary += s;
        } else {
            if (y_count > 0 && s > y[0]) {
                total_salary += s - y[0]; // Replace the smallest salary
                y[0] = s;
                // Re-heapify y
                for (int j = 0; j < y_count; j++) {
                    if (y[j] < y[0]) {
                        int temp = y[j];
                        y[j] = y[0];
                        y[0] = temp;
                    }
                }
            }
        }
    }

    printf("%d\n", total_salary);

    free(jobs);
    free(y);
    return 0;
}

// <END-OF-CODE>
