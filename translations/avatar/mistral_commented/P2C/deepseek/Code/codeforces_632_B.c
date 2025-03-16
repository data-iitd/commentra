#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function is the entry point of the program
void main() {
    // Read input from standard input
    char input[100];
    fgets(input, sizeof(input), stdin);

    // Parse input into a tuple of pairs, where each pair contains the score and the player of a piece
    int scores[100];
    char players[100][100];
    int count = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        scores[count] = atoi(token);
        token = strtok(NULL, " ");
        strcpy(players[count], token);
        token = strtok(NULL, " ");
        count++;
    }

    // Call the function to find Bob's maximum strength
    int result = Bob_sMaxStrength(scores, players, count);

    // Print the result
    printf("%d\n", result);
}

// This function calculates Bob's maximum strength based on the given pieces
int Bob_sMaxStrength(int scores[], char players[][100], int count) {
    // Initialize variables to store the scores for players A and B
    int p_score = 0, s_score = 0;
    int p_max_score = 0, s_max_score = 0;

    // Iterate through each piece and update the scores accordingly
    for (int i = 0; i < count; i++) {
        // If the piece belongs to player A, add its score to p_score
        if (strcmp(players[i], "A") == 0) {
            p_score += scores[i];
            // Update p_max_score if the current p_score is greater
            if (p_score > p_max_score) {
                p_max_score = p_score;
            }
        }
        // If the piece belongs to player B, subtract its score from p_score
        else {
            p_score -= scores[i];
        }
    }

    // Iterate through the pieces in reverse order and update the scores for player S
    for (int i = count - 1; i >= 0; i--) {
        // If the current piece belongs to player A, add its score to s_score
        if (strcmp(players[i], "A") == 0) {
            s_score += scores[i];
            // Update s_max_score if the current s_score is greater
            if (s_score > s_max_score) {
                s_max_score = s_score;
            }
        }
        // If the current piece belongs to player B, subtract its score from s_score
        else {
            s_score -= scores[i];
        }
    }

    // Return the maximum score between Bob's and Sally's scores
    if (p_max_score > s_max_score) {
        return p_max_score;
    }
    return s_max_score;
}
