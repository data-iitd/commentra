#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int score;
    char player;
} Piece;

// Function to calculate Bob's maximum strength based on the given pieces
int Bob_sMaxStrength(Piece* pieces, int n) {
    int p_score = 0, s_score = 0;
    int p_max_score = 0, s_max_score = 0;

    // Iterate through each piece and update the scores accordingly
    for (int i = 0; i < n; i++) {
        // If the piece belongs to player A, add its score to p_score
        if (pieces[i].player == 'A') {
            p_score += pieces[i].score;
            // Update p_max_score if the current p_score is greater
            if (p_score > p_max_score) {
                p_max_score = p_score;
            }
        } else { // If the piece belongs to player B
            p_score -= pieces[i].score;
        }
    }

    // Iterate through the pieces in reverse order and update the scores for player S
    for (int i = n - 1; i >= 0; i--) {
        // If the current piece belongs to player A, add its score to s_score
        if (pieces[i].player == 'A') {
            s_score += pieces[i].score;
            // Update s_max_score if the current s_score is greater
            if (s_score > s_max_score) {
                s_max_score = s_score;
            }
        } else { // If the current piece belongs to player B
            s_score -= pieces[i].score;
        }
    }

    // Return the maximum score between Bob's and Sally's scores
    return (p_max_score > s_max_score) ? p_max_score : s_max_score;
}

// This function is the entry point of the program
int main() {
    int n;
    // Read the number of pieces
    scanf("%d", &n);

    // Allocate memory for pieces
    Piece* pieces = (Piece*)malloc(n * sizeof(Piece));

    // Read the scores and players
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &pieces[i].score, &pieces[i].player);
    }

    // Call the function to find Bob's maximum strength
    int result = Bob_sMaxStrength(pieces, n);

    // Print the result
    printf("%d\n", result);

    // Free allocated memory
    free(pieces);

    return 0;
}

// <END-OF-CODE>
