#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 22
#define MAX_ABSENCES 33

// Define a structure to hold a pair of an integer and a string
typedef struct {
    int first;
    char second[100]; // Assuming a maximum length for the name
} P;

// Initialize an array of pairs v with size MAX_STUDENTS
P v[MAX_STUDENTS];

// Initialize an array of integer vectors d with size MAX_ABSENCES
int d[MAX_ABSENCES][MAX_STUDENTS]; // To store indices of students
int d_size[MAX_ABSENCES]; // To keep track of the size of each vector

// Main function
int main(void) {
    int n, m;

    // Read the number of test cases n
    while (scanf("%d", &n) && n) {
        // Initialize d array for each test case
        for (int i = 0; i < MAX_ABSENCES; i++) {
            d_size[i] = 0; // Clear the size of each vector
        }

        // Process each test case
        for (int i = 0; i < n; i++) {
            // Initialize the first element of pair v[i] as 0
            v[i].first = 0;

            // Read the name and number of students m for the current test case
            scanf("%s %d", v[i].second, &m);

            // For each student, read the number of absences a and update the scores accordingly
            for (int j = 0; j < m; j++) {
                int a;
                // Read the number of absences a for the current student
                scanf("%d", &a);

                // Calculate the effect of the current student's absences on the scores of other students
                v[i].first += n - d_size[a];

                // Update the scores of students who have the same number of absences as the current student
                for (int k = 0; k < d_size[a]; k++) {
                    // Decrease the score of the student whose index is in d[a] by 1
                    v[d[a][k]].first--;
                }

                // Add the index of the current student to the array d[a]
                d[a][d_size[a]] = i;
                d_size[a]++;
            }
        }

        // Sort the pairs in the array v in ascending order based on their first elements
        qsort(v, n, sizeof(P), [](const void *a, const void *b) {
            return ((P *)a)->first - ((P *)b)->first;
        });

        // Print the name and the highest score of the student with the highest score
        printf("%d %s\n", v[0].first, v[0].second);
    }

    return 0;
}

// <END-OF-CODE>
