
#include <stdio.h>
#include <math.h>

int main() {
    // Step 1: Reading Input
    // The code reads the number of points N and the coordinates of the points XY from the standard input.
    int N;
    scanf("%d", &N);
    double XY[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%lf%lf", &XY[i][0], &XY[i][1]);
    }

    // Step 2: Processing Coordinates
    // The coordinates are grouped into pairs and stored in the array XY.

    // Step 3: Calculating Angles
    // For each point, the code calculates the angles to all other points using atan2.
    double D[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i!= j) {
                D[i] = atan2(XY[j][0] - XY[i][0], XY[j][1] - XY[i][1]);
            }
        }

        // Step 4: Handling Circular Angles
        // The angles are adjusted to handle the circular nature of angles (0 to 2π).
        D[i] += 2 * M_PI;

        // Step 5: Finding the Maximum Gap
        double ans = 0;
        for (int j = 0; j < N; j++) {
            if (j!= i) {
                if (D[j] - D[i] >= M_PI) {
                    ans = fmax(ans, D[j] - D[i] - M_PI);
                }
            }
        }

        // Step 6: Calculating the Fraction
        // The fraction of the circle covered by the maximum gap is calculated and printed.
        printf("%.10lf\n", ans / (2 * M_PI));
    }

    return 0;
}
