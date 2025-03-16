#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int salary;
} Job;

int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    // Sort by day in descending order
    return jobB->day - jobA->day;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Job *jobs = (Job *)malloc(n * sizeof(Job));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jobs[i].day, &jobs[i].salary);
    }

    // Sort jobs by day (deadline) in descending order
    qsort(jobs, n, sizeof(Job), compare);

    int *salaries = (int *)malloc(m * sizeof(int));
    int count = 0;
    int totalSalary = 0;

    for (int i = 0; i < n; i++) {
        if (count < m) {
            // If we have space, add the salary
            salaries[count++] = jobs[i].salary;
            totalSalary += jobs[i].salary;
        } else {
            // If we don't have space, check if we can replace the smallest salary
            int minSalaryIndex = 0;
            for (int j = 1; j < m; j++) {
                if (salaries[j] < salaries[minSalaryIndex]) {
                    minSalaryIndex = j;
                }
            }
            if (jobs[i].salary > salaries[minSalaryIndex]) {
                totalSalary += jobs[i].salary - salaries[minSalaryIndex];
                salaries[minSalaryIndex] = jobs[i].salary;
            }
        }
    }

    printf("%d\n", totalSalary);

    free(jobs);
    free(salaries);
    return 0;
}

// <END-OF-CODE>
