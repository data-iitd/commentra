#include <stdio.h>

int main() {
    // Read the number of rounds (n) and the number of George's complexities (m)
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Read the complexities for each round into an array
    int round_complexity[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &round_complexity[i]);
    }
    
    // Read George's complexities into another array
    int george_complexity[m];
    for (int j = 0; j < m; j++) {
        scanf("%d", &george_complexity[j]);
    }
    
    // Initialize indices for both arrays
    int i = 0, j = 0;
    
    // Iterate through both arrays to compare complexities
    while (i < n && j < m) {
        // If the current round's complexity is less than or equal to George's complexity,
        // move to the next round
        if (round_complexity[i] <= george_complexity[j]) {
            i++;
        }
        // Always move to the next complexity of George
        j++;
    }
    
    // Output the number of rounds that George cannot handle
    printf("%d\n", n - i);

    return 0;
}

// <END-OF-CODE>
