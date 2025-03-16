#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int salary;
} Employee;

int compare(const void *a, const void *b) {
    Employee *empA = (Employee *)a;
    Employee *empB = (Employee *)b;
    if (empA->day == empB->day) {
        return empA->salary - empB->salary;
    }
    return empA->day - empB->day;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Employee *employees = (Employee *)malloc(n * sizeof(Employee));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &employees[i].day, &employees[i].salary);
        employees[i].day = -employees[i].day; // Store negative day
        employees[i].salary = -employees[i].salary; // Store negative salary
    }

    // Sort employees based on day (and salary if days are equal)
    qsort(employees, n, sizeof(Employee), compare);

    int *salaries = (int *)malloc(m * sizeof(int));
    int count = 0;
    int totalSalary = 0;

    for (int i = 0; i < n; i++) {
        int d = employees[i].day;
        int s = employees[i].salary;

        if (count < m) {
            // If we can add the employee
            salaries[count++] = s;
            totalSalary += -s; // Add the salary (negate back)
        } else {
            // If we cannot add, we need to replace the employee with the lowest salary
            int minSalaryIndex = 0;
            for (int j = 1; j < count; j++) {
                if (salaries[j] < salaries[minSalaryIndex]) {
                    minSalaryIndex = j;
                }
            }
            if (salaries[minSalaryIndex] < s) {
                totalSalary += -salaries[minSalaryIndex] + -s; // Replace and update total salary
                salaries[minSalaryIndex] = s; // Replace the lowest salary
            }
        }
    }

    printf("%d\n", totalSalary);

    free(employees);
    free(salaries);
    return 0;
}

// <END-OF-CODE>
