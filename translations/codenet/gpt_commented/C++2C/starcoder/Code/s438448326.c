#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables to hold input values
    int A, B, C, D, E, F;
    
    // Read input values from the user
    scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

    // Initialize variables to track the maximum values and the corresponding amounts
    int m1 = 0, m2 = 0;
    float maxD = 0.f;

    // Iterate over possible values of A (scaled by 100)
    for (size_t i = 0; 100 * A * i <= F; i++) {
        int mA = 100 * A * i; // Calculate the total amount for A

        // Iterate over possible values of B (scaled by 100)
        for (size_t j = 0; mA + 100 * B * j <= F; j++) {
            int mB = 100 * B * j; // Calculate the total amount for B

            // Iterate over possible values of C
            for (size_t k = 0; mA + mB + C * k <= F; k++) {
                int mC = C * k; // Calculate the total amount for C

                // Iterate over possible values of D
                for (size_t l = 0; mA + mB + mC + D * l <= F; l++) {
                    int mD = D * l; // Calculate the total amount for D

                    // Check if the condition for the ratio is satisfied
                    if ((mA + mB) * E / 100 < mD + mC) {
                        break; // Exit the loop if the condition is not met
                    }

                    // Calculate the current ratio of (mD + mC) to the total amount
                    float d = (float)(mD + mC) / (float)(mA + mB + mC + mD);
                    
                    // Update maximum values if the current ratio is greater
                    if (d > maxD) {
                        m1 = mA + mB + mC + mD; // Update total amount
                        m2 = mC + mD; // Update amount of C and D
                        maxD = d; // Update maximum ratio
                    }
                }
            }
        }
    }

    // If no valid combination was found, set m1 to the minimum amount for A
    if (m1 == 0) {
        m1 = 100 * A;
    }

    // Output the results
    printf("%d %d\n", m1, m2);
    return 0;
}
