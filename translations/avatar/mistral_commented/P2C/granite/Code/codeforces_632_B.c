
#include <stdio.h>
#include <stdlib.h>

// This function is the entry point of the program
int main() {
    // Read input from standard input
    int n;
    scanf("%d", &n);

    // Parse input into a tuple of pairs, where each pair contains the score and the player of a piece
    int scores[n][2];
    char players[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &scores[i][0], &players[i]);
        scores[i][1] = (players[i] == 'A')? 1 : 0;
    }

    // Call the function to find Bob's maximum strength
    int result = Bob_sMaxStrength(scores, players, n);

    // Print the result
    printf("%d\n", result);

    return 0;
}

// This function calculates Bob's maximum strength based on the given pieces
int Bob_sMaxStrength(int scores[n][2], char players[n], int n) {
    // Initialize variables to store the scores for players A and B
    int p_score = s_score = p_max_score = s_max_score = 0;

    // Iterate through each piece and update the scores accordingly
    for (int i = 0; i < n; i++) {
        // If the piece belongs to player A, add its score to p_score
        if (players[i] == 'A') {
            p_score += scores[i][0];
            // Update p_max_score if the current p_score is greater
            if (p_score > p_max_score) {
                p_max_score = p_score;
            }
        }
        // If the piece belongs to player B, subtract its score from p_score
        else {
            p_score -= scores[i][0];
        }
    }

    // Iterate through the pieces in reverse order and update the scores for player S
    for (int i = n-1; i >= 0; i--) {
        // If the current piece belongs to player A, add its score to s_score
        if (players[i] == 'A') {
            s_score += scores[i][0];
            // Update s_max_score if the current s_score is greater
            if (s_score > s_max_score) {
                s_max_score = s_score;
            }
        }
        // If the current piece belongs to player B, subtract its score from s_score
        else {
            s_score -= scores[i][0];
        }
    }

    // Return the maximum score between Bob's and Sally's scores
    if (p_max_score > s_max_score) {
        return p_max_score;
    }
    return s_max_score;
}

// End of code