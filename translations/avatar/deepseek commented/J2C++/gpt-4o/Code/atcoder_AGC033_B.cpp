#include <iostream>
#include <string>
using namespace std;

int main() {
    // Reading input values
    int h, w, n, sr, sc;
    cin >> h >> w >> n >> sr >> sc;

    // Reading the moves
    string s, t;
    cin >> s >> t;

    // Initializing variables to track safe bounds
    bool end = false; // Flag to check if an unsafe condition is encountered
    int usafe = 1; // Safe upper bound for row
    int dsafe = h; // Safe lower bound for row

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
                dsafe = min(dsafe + 1, h); // Adjust lower safe bound if previous move was up
            } else if (t[i - 1] == 'D') {
                usafe = max(usafe - 1, 1); // Adjust upper safe bound if previous move was down
            }
        }
    }

    // Initializing variables to track safe bounds for columns
    int lsafe = 1; // Safe left bound for column
    int rsafe = w; // Safe right bound for column

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
                rsafe = min(rsafe + 1, w); // Adjust right safe bound if previous move was left
            } else if (t[i - 1] == 'R') {
                lsafe = max(lsafe - 1, 1); // Adjust left safe bound if previous move was right
            }
        }
    }

    // Checking if the final position is safe
    if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end) {
        cout << "YES" << endl; // Output YES if safe
    } else {
        cout << "NO" << endl; // Output NO if not safe
    }

    return 0;
}

// <END-OF-CODE>
