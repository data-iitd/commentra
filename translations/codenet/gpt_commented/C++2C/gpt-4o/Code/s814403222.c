#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTICIPANTS 22
#define MAX_SCORES 33

// Define a structure to hold an integer and a string
typedef struct {
    int score;
    char name[100]; // Assuming a maximum name length of 99 characters
} Participant;

// Array to hold participants
Participant participants[MAX_PARTICIPANTS];

// Array to hold lists of indices for each score
int score_indices[MAX_SCORES][MAX_PARTICIPANTS];
int score_count[MAX_SCORES];

<<<<<<< HEAD
=======
int compare(const void *a, const void *b) {
    Participant *p1 = (Participant *)a;
    Participant *p2 = (Participant *)b;
    // Sort in descending order of scores
    return p2->score - p1->score;
}

>>>>>>> 98c87cb78a (data updated)
int main(void) {
    int n; // Variable to hold the number of participants

    // Read the number of participants until a zero is encountered
    while (scanf("%d", &n) && n) {
        int m; // Variable to hold the number of scores for each participant

        // Clear the previous data in the score indices
        for (int i = 0; i < MAX_SCORES; i++) {
<<<<<<< HEAD
            score_count[i] = 0; // Reset the count of scores
=======
            score_count[i] = 0;
>>>>>>> 98c87cb78a (data updated)
        }

        // Loop through each participant
        for (int i = 0; i < n; i++) {
            participants[i].score = 0; // Initialize the score of the participant to zero

            // Read the participant's name and the number of scores
            scanf("%s %d", participants[i].name, &m);

            // Loop through each score for the current participant
            for (int j = 0; j < m; j++) {
                int a; // Variable to hold the score value
                scanf("%d", &a); // Read the score

                // Update the score of the current participant
                participants[i].score += n - score_count[a];

                // Decrease the score of participants who have already received this score
                for (int k = 0; k < score_count[a]; k++) {
                    participants[score_indices[a][k]].score--;
                }

                // Add the current participant's index to the list for this score
                score_indices[a][score_count[a]] = i;
                score_count[a]++;
            }
        }

        // Sort the participants based on their scores
<<<<<<< HEAD
        qsort(participants, n, sizeof(Participant), [](const void *a, const void *b) {
            return ((Participant *)b)->score - ((Participant *)a)->score; // Sort in descending order
        });
=======
        qsort(participants, n, sizeof(Participant), compare);
>>>>>>> 98c87cb78a (data updated)

        // Output the participant with the highest score
        printf("%d %s\n", participants[0].score, participants[0].name);
    }

    return 0;
}

// <END-OF-CODE>
