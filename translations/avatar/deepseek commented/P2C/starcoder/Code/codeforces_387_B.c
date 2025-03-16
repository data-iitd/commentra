#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Read the number of elements in round_complexity and george_complexity
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Read the complexities of the rounds
    int *round_complexity = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", round_complexity + i);
    
    // Read the complexities of George's challenges
    int *george_complexity = (int *) malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        scanf("%d", george_complexity + i);
    
    // Initialize counters for both lists
    int i = 0, j = 0;
    
    // Loop through both lists to compare complexities
    while (i < n && j < m)
    {
        // Increment i if the current round complexity is less than or equal to George's complexity
        i += 1 * (round_complexity[i] <= george_complexity[j]);
        
        // Increment j to move to the next element in george_complexity
        j += 1;
    }
    
    // Print the number of rounds George can solve
    printf("%d\n", n - i);
    
    // Free the memory
    free(round_complexity);
    free(george_complexity);
    
    return 0;
}

