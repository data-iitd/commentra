#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Read the number of rounds (n) and the number of George's complexities (m)
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Read the complexities for each round into a list
    int *round_complexity = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &round_complexity[i]);
    }
    
    // Read George's complexities into another list
    int *george_complexity = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &george_complexity[i]);
    }
    
    // Initialize indices for both lists
    int i = 0, j = 0;
    
    // Iterate through both lists to compare complexities
    while (i < n && j < m)
    {
        // If the current round's complexity is less than or equal to George's complexity,
        // move to the next round
        i += 1 * (round_complexity[i] <= george_complexity[j]);
        
        // Always move to the next complexity of George
        j += 1;
    }
    
    // Output the number of rounds that George cannot handle
    printf("%d\n", n - i);
    
    // Free memory
    free(round_complexity);
    free(george_complexity);
    
    return 0;
}

