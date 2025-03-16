
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Take input from the user
    scanf("%*s");
    // Process the input to get a tuple of (value, type) pairs for each piece
    int pieces[100000];
    int pieceCount = 0;
    char pieceType;
    int pieceValue;
    while (scanf("%d%c", &pieceValue, &pieceType) == 2)
    {
        pieces[pieceCount++] = pieceValue * (pieceType == 'B'? 1 : -1);
    }
    // Call the Bob_sMaxStrength function with the processed pieces and return its result
    return Bob_sMaxStrength(pieces, pieceCount);
}

int Bob_sMaxStrength(int *pieces, int pieceCount)
{
    // Initialize scores for both ends and their maximum scores
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
    for (int i = 0; i < pieceCount; i++)
    {
        pScore += pieces[i] > 0? pieces[i] : 0;
        sScore += pieces[i] < 0? -pieces[i] : 0;
        pMaxScore = pScore > pMaxScore? pScore : pMaxScore;
        sMaxScore = sScore > sMaxScore? sScore : sMaxScore;
    }
    // Return the maximum score between the two ends
    return pMaxScore > sMaxScore? pMaxScore : sMaxScore;
}

