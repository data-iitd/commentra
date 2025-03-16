#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store employee details
struct employee {
    int day;
    int salary;
};

// Function to compare two employees based on their salaries
int compare(const void *a, const void *b) {
    struct employee *e1 = (struct employee *)a;
    struct employee *e2 = (struct employee *)b;
    return e1->salary - e2->salary;
}

int main() {
    // Taking input of number of days and number of employees
    int n, m;
    scanf("%d %d", &n, &m);

    // Initializing empty lists for storing days and salaries
    struct employee *x = (struct employee *)malloc(n * sizeof(struct employee));
    int *y = (int *)malloc(m * sizeof(int));

    // Iterating through each employee and adding their details to the heap 'x'
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i].day, &x[i].salary);
    }

    // Sorting the list 'x' based on salaries
    qsort(x, n, sizeof(struct employee), compare);

    // Simulation loop to check if an employee can be added to the list 'y'
    for (int i = 0; i < n; i++) {
        // Calculating the remaining capacity in the list 'y'
        int r = m - i;
        // Checking if the remaining capacity is enough to add the current employee
        if (r >= x[i].day) {
            // If yes, adding the salary of the employee to the list 'y'
            y[i] = x[i].salary;
        } else {
            // If no, removing an employee with minimum salary from the list 'y' and adding the current employee
            y[i] = x[i].salary;
            y[i - 1] = 0;
        }
    }

    // Printing the sum of salaries of employees in the list 'y'
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += y[i];
    }
    printf("%d", sum);

    // Freeing memory allocated to lists
    free(x);
    free(y);

    return 0;
}

