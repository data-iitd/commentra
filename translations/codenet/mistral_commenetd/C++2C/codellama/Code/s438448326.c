
#include <stdio.h>
#include <stdlib.h>

// Main function
int main() {
	// Initialize variables
	int A, B, C, D, E, F;
	scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

	// Initialize variables for storing maximum sum and its components
	int m1 = 0, m2 = 0;
	float maxD = 0.f;

	// Loop through all possible combinations of mA, mB, mC, mD that satisfy the condition F >= mA + mB + mC + mD
	for (size_t i = 0; 100*A*i <= F; i++) {
		// Calculate current value of mA
		int mA = 100 * A*i;

		// Loop through all possible combinations of mB, mC, mD that satisfy the condition mA + 100*B*j <= F
		for (size_t j = 0; mA+100*B*j <= F; j++) {
			// Calculate current value of mB
			int mB = 100 * B*j;

			// Loop through all possible combinations of mC, mD that satisfy the condition mA + mB + C*k <= F
			for (size_t k = 0; mA+mB+C*k <= F; k++) {
				// Calculate current value of mC
				int mC = C*k;

				// Loop through all possible combinations of mD that satisfy the condition mA + mB + mC + D*l <= F
				for (size_t l = 0; mA+mB+mC+D*l <= F; l++) {
					// Calculate current value of mD
					int mD = D*l;

					// Check if the current combination satisfies the condition (mA + mB)*E / 100 < mD + mC
					if ((mA + mB)*E / 100 < mD + mC) {
						// If so, break out of the inner loop and move on to the next combination of mA, mB, mC, mD
						break;
					}

					// Calculate the ratio d = (mD + mC) / (mA + mB + mC + mD)
					float d = (float)(mD + mC) / (float)(mA + mB + mC + mD);

					// If the current ratio is greater than the maximum ratio found so far, update the maximum ratio and the corresponding values of m1 and m2
					if (d > maxD) {
						m1 = mA + mB + mC + mD;
						m2 = mC + mD;
						maxD = d;
					}
				}

			}

		}

	}

	// If no combination was found that satisfies the conditions, set m1 to the value of 100*A and print the result as 0 0
	if (m1 == 0) {
		m1 = 100 * A;
	}

	// Print the result
	printf("%d %d\n", m1, m2);

	// Return 0 to indicate successful execution
	return 0;
}

