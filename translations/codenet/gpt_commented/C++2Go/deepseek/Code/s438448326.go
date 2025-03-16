package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold input values
	var A, B, C, D, E, F int
	
	// Read input values from the user
	fmt.Scan(&A, &B, &C, &D, &E, &F)

	// Initialize variables to track the maximum values and the corresponding amounts
	var m1, m2 int
	var maxD float64 = 0.0

	// Iterate over possible values of A (scaled by 100)
	for i := 0; 100 * A * i <= F; i++ {
		mA := 100 * A * i

		// Iterate over possible values of B (scaled by 100)
		for j := 0; mA + 100 * B * j <= F; j++ {
			mB := 100 * B * j

			// Iterate over possible values of C
			for k := 0; mA + mB + C * k <= F; k++ {
				mC := C * k

				// Iterate over possible values of D
				for l := 0; mA + mB + mC + D * l <= F; l++ {
					mD := D * l

					// Check if the condition for the ratio is satisfied
					if (mA + mB) * E / 100 < mD + mC {
						break // Exit the loop if the condition is not met
					}

					// Calculate the current ratio of (mD + mC) to the total amount
					d := float64(mD + mC) / float64(mA + mB + mC + mD)
					
					// Update maximum values if the current ratio is greater
					if d > maxD {
						m1 = mA + mB + mC + mD // Update total amount
						m2 = mC + mD // Update amount of C and D
						maxD = d // Update maximum ratio
					}
				}
			}
		}
	}

	// If no valid combination was found, set m1 to the minimum amount for A
	if m1 == 0 {
		m1 = 100 * A
	}

	// Output the results
	fmt.Println(m1, m2)
}

