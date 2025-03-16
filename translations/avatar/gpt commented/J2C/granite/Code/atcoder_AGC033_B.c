
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    int h, w, n, sr, sc;
    char s[100001], t[100001];
    scanf("%d %d %d %d %s %s", &h, &w, &n, &sr, &sc, s, t);

    // Initialize a flag to indicate if the position is unsafe
    int end = 0;

    // Initialize the safe boundaries for vertical movement
    int usafe = 1, dsafe = h;

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
            end = 1;
            break;
        }

        // Adjust the safe boundaries based on the obstacles
        if (i > 0) {
            if (t[i - 1] == 'U') {
                dsafe = dsafe < h? dsafe + 1 : h;
            } else if (t[i - 1] == 'D') {
                usafe = usafe > 1? usafe - 1 : 1;
            }
        }
    }

    // Initialize the safe boundaries for horizontal movement
    int lsafe = 1, rsafe = w;

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
            end = 1;
            break;
        }

        // Adjust the safe boundaries based on the obstacles
        if (i > 0) {
            if (t[i - 1] == 'L') {
                rsafe = rsafe < w? rsafe + 1 : w;
            } else if (t[i - 1] == 'R') {
                lsafe = lsafe > 1? lsafe - 1 : 1;
            }
        }
    }

    // Check if the starting position is within the safe boundaries and not marked as unsafe
    if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe &&!end) {
        printf("YES\n"); // Output "YES" if the position is safe
    } else {
        printf("NO\n"); // Output "NO" if the position is unsafe
    }

    return 0;
}
// END-OF-CODE