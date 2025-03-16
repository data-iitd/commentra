#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Define a pair type to hold an integer and a string
typedef struct {
    int score;
    char name[100];
} P;

// Array to hold pairs of scores and names
P v[22];

// Vector to hold lists of indices for each number
int d[33];

int main(void) {
    int n; // Variable to hold the number of participants

    // Read the number of participants until a zero is encountered
    while(scanf("%d", &n) && n) {
        int m; // Variable to hold the number of scores for each participant

        // Clear the previous data in the vector of lists
        for(int i = 0; i < 33; i++) d[i] = 0;

        // Loop through each participant
        for(int i = 0; i < n; i++) {
            v[i].score = 0; // Initialize the score of the participant to zero

            // Read the participant's name and the number of scores
            scanf("%s %d", v[i].name, &m);

            // Loop through each score for the current participant
            for(int j = 0; j < m; j++) {
                int a; // Variable to hold the score value
                scanf("%d", &a); // Read the score

                // Update the score of the current participant
                v[i].score += n - d[a];

                // Decrease the score of participants who have already received this score
                for(int k = 0; k < d[a]; k++) {
                    v[d[a][k]].score--;
                }

                // Add the current participant's index to the list for this score
                d[a]++;
            }
        }

        // Sort the participants based on their scores
        qsort(v, n, sizeof(P), cmp);

        // Output the participant with the highest score
        printf("%d %s\n", v[0].score, v[0].name);
    }
}

