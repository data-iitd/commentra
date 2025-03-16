#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function is the entry point of the program
int main() {
    // Read input from standard input
    char input[100];
    fgets(input, 100, stdin);

    // Parse input into a tuple of pairs, where each pair contains the score and the player of a piece
    int pieces[100][2];
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
        pieces[i][0] = atoi(token);
        token = strtok(NULL, " ");
        pieces[i][1] = *token;
        token = strtok(NULL, " ");
        i++;
    }

    // Call the function to find Bob's maximum strength
    int result = Bob_sMaxStrength(pieces, i);

    // Print the result
    printf("%d\n", result);

    return 0;
}

// This function calculates Bob's maximum strength based on the given pieces
int Bob_sMaxStrength(int pieces[][2], int n) {
    // Initialize variables to store the scores for players A and B
    int p_score = 0, s_score = 0, p_max_score = 0, s_max_score = 0;

    // Iterate through each piece and update the scores accordingly
    for (int i = 0; i < n; i++) {
        // If the piece belongs to player A, add its score to p_score
        if (pieces[i][1] == 'A') {
            p_score += pieces[i][0];
            // Update p_max_score if the current p_score is greater
            if (p_score > p_max_score) {
                p_max_score = p_score;
            }
        }
        // If the piece belongs to player B, subtract its score from p_score
        else {
            p_score -= pieces[i][0];
        }
    }

    // Iterate through the pieces in reverse order and update the scores for player S
    for (int i = n-1; i >= 0; i--) {
        // If the current piece belongs to player A, add its score to s_score
        if (pieces[i][1] == 'A') {
            s_score += pieces[i][0];
            // Update s_max_score if the current s_score is greater
            if (s_score > s_max_score) {
                s_max_score = s_score;
            }
        }
        // If the current piece belongs to player B, subtract its score from s_score
        else {
            s_score -= pieces[i][0];
        }
    }

    // Return the maximum score between Bob's and Sally's scores
    if (p_max_score > s_max_score) {
        return p_max_score;
    }
    return s_max_score;
}

// 