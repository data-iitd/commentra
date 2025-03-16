#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int h, w, n, sr, sc; 
    char s[1000], t[1000]; 
    int i, j; 
    int usafe, dsafe, lsafe, rsafe; 
    int end; 
    
    // Read the height (h), width (w), number of moves (n), starting row (sr), and starting column (sc)
    scanf("%d %d %d %d %d", &h, &w, &n, &sr, &sc); 
    
    // Read the strings representing the moves and the obstacles
    scanf("%s %s", s, t); 
    
    // Initialize a flag to indicate if the position is unsafe
    end = 0; 
    
    // Initialize the safe boundaries for vertical movement
    usafe = 1; // Upper safe boundary
    dsafe = h; // Lower safe boundary
    
    // Process the vertical moves in reverse order
    for (i = n - 1; i >= 0; i--) { 
        // Update the safe boundaries based on the moves
        if (s[i] == 'U') { 
            usafe++; 
        } else if (s[i] == 'D') { 
            dsafe--; 
        } 
        
        // Check if the upper safe boundary exceeds the lower safe boundary
        if (usafe > dsafe) { 
            end = 1; 
            break; 
        } 
        
        // Adjust the safe boundaries based on the obstacles
        if (i > 0) { 
            if (t[i - 1] == 'U') { 
                dsafe = dsafe + 1; 
                if (dsafe > h) { 
                    dsafe = h; 
                } 
            } else if (t[i - 1] == 'D') { 
                usafe = usafe - 1; 
                if (usafe < 1) { 
                    usafe = 1; 
                } 
            } 
        } 
    } 
    
    // Initialize the safe boundaries for horizontal movement
    lsafe = 1; // Left safe boundary
    rsafe = w; // Right safe boundary
    
    // Process the horizontal moves in reverse order
    for (i = n - 1; i >= 0; i--) { 
        // Update the safe boundaries based on the moves
        if (s[i] == 'L') { 
            lsafe++; 
        } else if (s[i] == 'R') { 
            rsafe--; 
        } 
        
        // Check if the left safe boundary exceeds the right safe boundary
        if (lsafe > rsafe) { 
            end = 1; 
            break; 
        } 
        
        // Adjust the safe boundaries based on the obstacles
        if (i > 0) { 
            if (t[i - 1] == 'L') { 
                rsafe = rsafe + 1; 
                if (rsafe > w) { 
                    rsafe = w; 
                } 
            } else if (t[i - 1] == 'R') { 
                lsafe = lsafe - 1; 
                if (lsafe < 1) { 
                    lsafe = 1; 
                } 
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
