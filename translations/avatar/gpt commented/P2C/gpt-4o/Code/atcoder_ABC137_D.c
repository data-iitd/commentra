#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int salary;
} Job;

int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    if (jobA->day != jobB->day) {
        return jobB->day - jobA->day; // Max-heap based on day
    }
    return jobB->salary - jobA->salary; // Max-heap based on salary
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

    int *selectedSalaries = (int *)malloc(m * sizeof(int));
    int count = 0;
    int totalSalary = 0;

    for (int i = 0; i < n; i++) {
        int day = jobs[i].day;
        int salary = jobs[i].salary;

        // Calculate remaining capacity for jobs
        int r = m - count;

        // If there is enough capacity to take the job
        if (r > 0) {
            selectedSalaries[count++] = salary;
            totalSalary += salary;
        } else {
            // If capacity is full, replace the lowest salary if the new salary is higher
            int minSalaryIndex = 0;
            for (int j = 1; j < count; j++) {
                if (selectedSalaries[j] < selectedSalaries[minSalaryIndex]) {
                    minSalaryIndex = j;
                }
            }
            if (salary > selectedSalaries[minSalaryIndex]) {
                totalSalary += salary - selectedSalaries[minSalaryIndex];
                selectedSalaries[minSalaryIndex] = salary;
            }
        }
    }

    printf("%d\n", totalSalary);

    free(jobs);
    free(selectedSalaries);
    return 0;
}

// <END-OF-CODE>
