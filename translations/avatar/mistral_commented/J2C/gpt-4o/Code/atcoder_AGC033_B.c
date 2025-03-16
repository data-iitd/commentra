#include <stdio.h>  // Including standard input-output library
#include <stdbool.h>  // Including library for boolean type
#include <string.h>  // Including string library for string manipulation

int main() {
    int h, w, n;  // Variables for height, width, and number of steps
    scanf("%d %d %d", &h, &w, &n);  // Reading height, width, and number of steps from input

    int sr, sc;  // Variables for starting row and column of the safe zone
    scanf("%d %d", &sr, &sc);  // Reading starting position of the safe zone

    char s[100001], t[100001];  // Arrays to hold the movement sequences
    scanf("%s %s", s, t);  // Reading the sequences of movements

    bool end = false;  // Boolean variable to track if the safe zone is valid
    int usafe = 1;  // Upper boundary of the safe zone
    int dsafe = h;  // Lower boundary of the safe zone

    // Loop to check vertical boundaries based on sequence 's'
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'U') {  // If the current character is 'U', increase the upper boundary
            usafe++;
        } else if (s[i] == 'D') {  // If the current character is 'D', decrease the lower boundary
            dsafe--;
        }
        if (usafe > dsafe) {  // If upper boundary exceeds lower boundary, the safe zone is invalid
            end = true;
            break;
        }
        if (i > 0) {  // Check previous character in sequence 't' to update boundaries
            if (t[i - 1] == 'U') {
                dsafe = (dsafe + 1 < h) ? dsafe + 1 : h;  // Increase lower boundary
            } else if (t[i - 1] == 'D') {
                usafe = (usafe - 1 > 1) ? usafe - 1 : 1;  // Decrease upper boundary
            }
        }
    }

    int lsafe = 1;  // Left boundary of the safe zone
    int rsafe = w;  // Right boundary of the safe zone

    // Loop to check horizontal boundaries based on sequence 't'
    for (int i = n - 1; i >= 0; i--) {
        if (t[i] == 'L') {  // If the current character is 'L', increase the left boundary
            lsafe++;
        } else if (t[i] == 'R') {  // If the current character is 'R', decrease the right boundary
            rsafe--;
        }
        if (lsafe > rsafe) {  // If left boundary exceeds right boundary, the safe zone is invalid
            end = true;
            break;
        }
        if (i > 0) {  // Check previous character in sequence 's' to update boundaries
            if (s[i - 1] == 'L') {
                rsafe = (rsafe + 1 < w) ? rsafe + 1 : w;  // Increase right boundary
            } else if (s[i - 1] == 'R') {
                lsafe = (lsafe - 1 > 1) ? lsafe - 1 : 1;  // Decrease left boundary
            }
        }
    }

    // Check if the starting position is within the safe zone boundaries and if the safe zone is valid
    if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end) {
        printf("YES\n");  // Print "YES" if the safe zone is valid
    } else {
        printf("NO\n");  // Print "NO" if the safe zone is invalid
    }

    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
