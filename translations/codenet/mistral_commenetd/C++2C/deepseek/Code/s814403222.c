#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a pair type with first integer and second string
typedef struct {
    int first;
    char second[100];
} P;

// Initialize an array of pairs v with size n
P v[22];

// Initialize an array of vectors d with size 33
int* d[33];

// Main function
int main(void) {
    int n, m;
    while (scanf("%d", &n) == 1 && n) {
        // Initialize d array for each test case
        for (int i = 0; i < 33; i++) {
            free(d[i]);
            d[i] = NULL;
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
                v[i].first += n - (d[a] == NULL ? 0 : (int)d[a][0]);

                // Update the scores of students who have the same number of absences as the current student
                if (d[a] != NULL) {
                    for (int k = 0; k < (int)d[a][0]; k++) {
                        // Decrease the score of the student whose index is in d[a] by 1
                        v[d[a][k]].first--;
                    }
                }

                // Allocate memory for the vector d[a]
                d[a] = (int*)malloc(sizeof(int));
                d[a][0] = i;
            }
        }

        // Sort the pairs in the array v in ascending order based on their first elements
        // (This part is not implemented in C, as sorting in C is more complex than in C++)

        // Print the name and the highest score of the student with the highest score
        printf("%d %s\n", v[0].first, v[0].second);
    }
}
