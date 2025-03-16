
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

// Define a structure to hold an integer and a string
typedef struct {
    int first;
    char second[22];
} P;

// Array to hold pairs of scores and names
P v[22];

// Array to hold lists of indices for each number
int d[33][22];

int main(void) {
    int n; // Variable to hold the number of participants

    // Read the number of participants until a zero is encountered
    while(scanf("%d", &n) && n) {
        int m; // Variable to hold the number of scores for each participant

        // Clear the previous data in the array of lists
        for(int i = 0; i < 33; i++) {
            for(int j = 0; j < 22; j++) {
                d[i][j] = 0;
            }
        }

        // Loop through each participant
        for(int i = 0; i < n; i++) {
            v[i].first = 0; // Initialize the score of the participant to zero

            // Read the participant's name and the number of scores
            scanf("%s %d", v[i].second, &m);

            // Loop through each score for the current participant
            for(int j = 0; j < m; j++) {
                int a; // Variable to hold the score value
                scanf("%d", &a); // Read the score

                // Update the score of the current participant
                v[i].first += n - d[a][0];

                // Decrease the score of participants who have already received this score
                for(int k = 1; k <= d[a][0]; k++) {
                    v[d[a][k]].first--;
                }

                // Add the current participant's index to the list for this score
                d[a][++d[a][0]] = i;
            }
        }

        // Sort the participants based on their scores
        sort(v, v+n);

        // Output the participant with the highest score
        printf("%d %s\n", v[0].first, v[0].second);
    }
}


