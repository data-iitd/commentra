#include <stdio.h>

int main() {
    int n, m;
    
    // Read the number of elements in round_complexity and george_complexity
    scanf("%d %d", &n, &m);
    
    int round_complexity[n];
    int george_complexity[m];
    
    // Read the complexities of the rounds
    for (int i = 0; i < n; i++) {
        scanf("%d", &round_complexity[i]);
    }
    
    // Read the complexities of George's challenges
    for (int i = 0; i < m; i++) {
        scanf("%d", &george_complexity[i]);
    }
    
    // Initialize counters for both lists
    int i = 0, j = 0;
    
    // Loop through both lists to compare complexities
    while (i < n && j < m) {
        // Increment i if the current round complexity is less than or equal to George's complexity
        if (round_complexity[i] <= george_complexity[j]) {
            i++;
        }
        
        // Increment j to move to the next element in george_complexity
        j++;
    }
    
    // Print the number of rounds George can solve
    printf("%d\n", n - i);
    
    return 0;
}
