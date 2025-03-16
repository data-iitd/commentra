#include <stdio.h>
#include <stdbool.h>

int main() {
    // Declare variables for height, width, number of moves, starting row, and starting column
    int h, w, n, sr, sc;
    
    // Read the height (h), width (w), number of moves (n), starting row (sr), and starting column (sc)
    scanf("%d %d %d %d %d", &h, &w, &n, &sr, &sc);
    
    // Read the strings representing the moves and the obstacles
    char s[100001], t[100001];
    scanf("%s %s", s, t);
    
    // Initialize a flag to indicate if the position is unsafe
    bool end = false;
    
    // Initialize the safe boundaries for vertical movement
    int usafe = 1; // Upper safe boundary
    int dsafe = h; // Lower safe boundary
    
    // Process the vertical moves in reverse order
    for (int i = n - 1; i >= 0; i--) {
        // Update the safe boundaries based on the moves
        if (s[i] == 'U') {
            usafe++;
        } else if (s[i] == 'D') {
            dsafe--;
        }
        
        // Check if the upper safe boundary exceeds the lower safe boundary
        if (usafe > dsafe) {
            end = true;
            break;
        }
        
        // Adjust the safe boundaries based on the obstacles
        if (i > 0) {
            if (t[i - 1] == 'U') {
                dsafe = (dsafe + 1 > h) ? h : dsafe + 1;
            } else if (t[i - 1] == 'D') {
                usafe = (usafe - 1 < 1) ? 1 : usafe - 1;
            }
        }
    }
    
    // Initialize the safe boundaries for horizontal movement
    int lsafe = 1; // Left safe boundary
    int rsafe = w; // Right safe boundary
    
    // Process the horizontal moves in reverse order
    for (int i = n - 1; i >= 0; i--) {
        // Update the safe boundaries based on the moves
        if (s[i] == 'L') {
            lsafe++;
        } else if (s[i] == 'R') {
            rsafe--;
        }
        
        // Check if the left safe boundary exceeds the right safe boundary
        if (lsafe > rsafe) {
            end = true;
            break;
        }
        
        // Adjust the safe boundaries based on the obstacles
        if (i > 0) {
            if (t[i - 1] == 'L') {
                rsafe = (rsafe + 1 > w) ? w : rsafe + 1;
            } else if (t[i - 1] == 'R') {
                lsafe = (lsafe - 1 < 1) ? 1 : lsafe - 1;
            }
        }
    }
    
    // Check if the starting position is within the safe boundaries and not marked as unsafe
    if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end) {
        printf("YES\n"); // Output "YES" if the position is safe
    } else {
        printf("NO\n"); // Output "NO" if the position is unsafe
    }
    
    return 0;
}

// <END-OF-CODE>
