#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INTERVALS 1000
#define MAX_ACTIONS 2000

typedef struct {
    int start;
    int end;
} Interval;

int main() {
    // Read input
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    // Parse the required integers from the input
    int m, s, f;
    sscanf(input, "%*s %d %d %d", &m, &s, &f);
    
    // Initialize the maximum time and an array to store the intervals
    int maxT = -1;
    Interval intervals[MAX_INTERVALS] = {0};
    
    // Read the intervals from the input and store them in the array
    for (int i = 0; i < m; i++) {
        int k, a, b;
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d %d %d", &k, &a, &b);
        intervals[k].start = a;
        intervals[k].end = b;
        if (k > maxT) {
            maxT = k;
        }
    }
    
    // Initialize a buffer to build the sequence of actions
    char actions[MAX_ACTIONS];
    int actionIndex = 0;
    
    // Determine the direction of movement and initialize the current position
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;
    
    // Variables to store the current interval's start and end
    int a = -1;
    int b = -1;
    
    // Build the sequence of actions based on the intervals and the current position
    for (int t = 1; t <= maxT; t++) {
        if (intervals[t].start != 0 || intervals[t].end != 0) {
            a = intervals[t].start;
            b = intervals[t].end;
        }
        if ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b)) {
            actions[actionIndex++] = 'X';
        } else {
            actions[actionIndex++] = M;
            cur += d;
        }
        if (cur == f) break;
    }
    
    // Continue moving in the determined direction until reaching the final position
    while (cur != f) {
        actions[actionIndex++] = M;
        cur += d;
    }
    
    // Null-terminate the actions string
    actions[actionIndex] = '\0';
    
    // Print the sequence of actions
    printf("%s\n", actions);
    
    return 0;
}

// <END-OF-CODE>
