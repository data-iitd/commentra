
#include <stdio.h>
#include <string.h>

int main() {
    int h, w, n, sr, sc, usafe, dsafe, lsafe, rsafe;
    char s[100001], t[100001];
    bool end = false;

    // Reading input values
    scanf("%d %d %d %d %d", &h, &w, &n, &sr, &sc);
    scanf("%s", s);
    scanf("%s", t);

    // Initializing variables to track safe bounds
    usafe = 1; // Safe upper bound for row
    dsafe = h; // Safe lower bound for row
    lsafe = 1; // Safe left bound for column
    rsafe = w; // Safe right bound for column

    // Processing moves in reverse order for rows
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'U') {
            usafe++; // Move up, increase upper safe bound
        } else if (s[i] == 'D') {
            dsafe--; // Move down, decrease lower safe bound
        }
        if (usafe > dsafe) { // Check if upper safe bound exceeds lower safe bound
            end = true; // Set end flag to true if unsafe
            break; // Break out of the loop
        }
        if (i > 0) { // Check if it's not the first move
            if (t[i - 1] == 'U') {
                dsafe = dsafe < h? dsafe + 1 : h; // Adjust lower safe bound if previous move was up
            } else if (t[i - 1] == 'D') {
                usafe = usafe > 1? usafe - 1 : 1; // Adjust upper safe bound if previous move was down
            }
        }
    }

    // Processing moves in reverse order for columns
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            lsafe++; // Move left, increase left safe bound
        } else if (s[i] == 'R') {
            rsafe--; // Move right, decrease right safe bound
        }
        if (lsafe > rsafe) { // Check if left safe bound exceeds right safe bound
            end = true; // Set end flag to true if unsafe
            break; // Break out of the loop
        }
        if (i > 0) { // Check if it's not the first move
            if (t[i - 1] == 'L') {
                rsafe = rsafe < w? rsafe + 1 : w; // Adjust right safe bound if previous move was left
            } else if (t[i - 1] == 'R') {
                lsafe = lsafe > 1? lsafe - 1 : 1; // Adjust left safe bound if previous move was right
            }
        }
    }

    // Checking if the final position is safe
    if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe &&!end) {
        printf("YES\n"); // Output YES if safe
    } else {
        printf("NO\n"); // Output NO if not safe
    }

    return 0;
}
