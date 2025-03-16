#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read input (the first input is ignored)
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    // Read the second line of input, split it into integers and corresponding characters,
    // and create a tuple of pieces where each piece is a tuple of (score, character)
    int n;
    scanf("%d", &n);
    int *scores = (int *)malloc(n * sizeof(int));
    char *chars = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &scores[i], &chars[i]);
    }
    
    // Call the function to calculate Bob's maximum strength and return the result
    int result = Bob_sMaxStrength(scores, chars, n);
    
    // Print the result
    printf("%d\n", result);
    
    // Free allocated memory
    free(scores);
    free(chars);
    
    return 0;
}

int Bob_sMaxStrength(int *scores, char *chars, int n) {
    // Initialize scores for player A and player B, and their maximum scores
    int pScore = 0, sScore = 0;
    int pMaxScore = 0, sMaxScore = 0;
    
    // Calculate maximum score for player A by iterating through pieces from the start
    for (int i = 0; i < n; i++) {
        if (chars[i] == 'A') {  // If the piece belongs to player A
            pScore += scores[i];  // Add the score of the piece to player A's score
            if (pScore > pMaxScore) {  // Update maximum score if current score exceeds it
                pMaxScore = pScore;
            }
        } else {  // If the piece belongs to player B
            pScore -= scores[i];  // Subtract the score of the piece from player A's score
        }
    }
    
    // Calculate maximum score for player B by iterating through pieces from the end
    for (int i = n - 1; i >= 0; i--) {
        if (chars[i] == 'A') {  // If the piece belongs to player A
            sScore += scores[i];  // Add the score of the piece to player B's score
            if (sScore > sMaxScore) {  // Update maximum score if current score exceeds it
                sMaxScore = sScore;
            }
        } else {  // If the piece belongs to player B
            sScore -= scores[i];  // Subtract the score of the piece from player B's score
        }
    }
    
    // Return the maximum score between player A and player B
    if (pMaxScore > sMaxScore) {
        return pMaxScore;
    }
    return sMaxScore;
}
