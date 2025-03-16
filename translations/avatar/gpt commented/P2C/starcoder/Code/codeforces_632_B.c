#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Read input (the first input is ignored)
    scanf("%*s");
    
    // Read the second line of input, split it into integers and corresponding characters,
    // and create a tuple of pieces where each piece is a tuple of (score, character)
    int pieces[1000];
    char chars[1000];
    int i;
    for (i = 0; i < 1000; i++)
    {
        scanf("%d%c", &pieces[i], &chars[i]);
    }
    
    // Call the function to calculate Bob's maximum strength and return the result
    return Bob_sMaxStrength(pieces, chars);
}

int Bob_sMaxStrength(int pieces[1000], char chars[1000])
{
    // Initialize scores for player A and player B, and their maximum scores
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (chars[i] == 'B')
        {
            pScore += pieces[i];
            if (pScore > pMaxScore)
            {
                pMaxScore = pScore;
            }
        }
        else
        {
            sScore += pieces[i];
            if (sScore > sMaxScore)
            {
                sMaxScore = sScore;
            }
        }
    }
    
    // Return the maximum score between player A and player B
    if (pMaxScore > sMaxScore)
    {
        return pMaxScore;
    }
    return sMaxScore;
}

