
#include <stdio.h>
#include <stdlib.h>

// Structure to store employee details
struct employee {
    int day;
    int salary;
};

// Function to compare two employee structures based on their salaries
int compare(const void *a, const void *b) {
    struct employee *e1 = (struct employee *)a;
    struct employee *e2 = (struct employee *)b;
    return e1->salary - e2->salary;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initializing empty arrays for storing days and salaries
    struct employee *x = (struct employee *)malloc(n * sizeof(struct employee));
    int y[m];

    // Iterating through each employee and adding their details to the array 'x'
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i].day, &x[i].salary);
    }

    // Sorting the array 'x' based on the salaries of employees in ascending order
    qsort(x, n, sizeof(struct employee), compare);

    // Simulation loop to check if an employee can be added to the array 'y'
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j < m && x[i].day <= m - j) {
            y[j++] = x[i].salary;
        }
    }

    // Printing the sum of salaries of employees in the array 'y'
    int sum = 0;
    for (int i = 0; i < j; i++) {
        sum += y[i];
    }
    printf("%d\n", sum);

    return 0;
}
