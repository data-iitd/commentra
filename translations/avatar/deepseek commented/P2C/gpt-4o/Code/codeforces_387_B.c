#include <stdio.h>

int main() {
    // Read the number of elements in round_complexity and george_complexity
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Read the complexities of the rounds
    int round_complexity[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &round_complexity[i]);
    }
    
    // Read the complexities of George's challenges
    int george_complexity[m];
    for (int j = 0; j < m; j++) {
        scanf("%d", &george_complexity[j]);
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

// <END-OF-CODE>
