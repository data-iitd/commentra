
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Take input from the user
    int n;
    scanf("%d", &n);
    // Process the input to get a tuple of (value, type) pairs for each piece
    int pieces[n][2];
    char type[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c", &pieces[i][0], &type[i]);
    }
    // Call the Bob_sMaxStrength function with the processed pieces and return its result
    int result = Bob_sMaxStrength(pieces, n);
    printf("%d", result);
    return 0;
}

int Bob_sMaxStrength(int pieces[][2], int n)
{
    // Initialize scores for both ends and their maximum scores
    int pScore = sScore = pMaxScore = sMaxScore = 0;
    for (int i = 0; i < n; i++)
    {
        if (pieces[i][1] == 'B')
        {
            pScore += pieces[i][0];
            if (pScore > pMaxScore)
            {
                pMaxScore = pScore;
            }
        }
    }
    
    // Calculate the score from the front (left to right)
    for (int i = 0; i < n; i++)
    {
        if (pieces[i][1] == 'A')
        {
            pScore += pieces[i][0];
            if (pScore > pMaxScore)
            {
                pMaxScore = pScore;
            }
        }
        else
        {
            pScore -= pieces[i][0];
        }
    }
    
    // Calculate the score from the back (right to left)
    for (int i = n - 1; i >= 0; i--)
    {
        if (pieces[i][1] == 'A')
        {
            sScore += pieces[i][0];
            if (sScore > sMaxScore)
            {
                sMaxScore = sScore;
            }
        }
        else
        {
            sScore -= pieces[i][0];
        }
    }
    
    // Return the maximum score between the two ends
    if (pMaxScore > sMaxScore)
    {
        return pMaxScore;
    }
    return sMaxScore;
}

// 